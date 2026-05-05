// Implement the PATRICIA (Radix Tree) algorithm and perform insert, search, and deletion operations
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Node structure for PATRICIA
class PatriciaNode {
public:
    bool isEndOfWord;
    unordered_map<char, pair<string, PatriciaNode*>> children;

    PatriciaNode() {
        isEndOfWord = false;
    }
};

class PatriciaTrie {
private:
    PatriciaNode* root;

    // Helper to find the common prefix length between two strings
    int getCommonPrefixLength(const string& s1, const string& s2) {
        int i = 0;
        int minLen = min(s1.length(), s2.length());
        while (i < minLen && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }

public:
    PatriciaTrie() {
        root = new PatriciaNode();
    }

    // Insert a word into the tree
    void insert(const string& word) {
        PatriciaNode* current = root;
        string remaining = word;

        while (!remaining.empty()) {
            char firstChar = remaining[0];

            // If no edge starts with this character, create a new one
            if (current->children.find(firstChar) == current->children.end()) {
                PatriciaNode* newNode = new PatriciaNode();
                newNode->isEndOfWord = true;
                current->children[firstChar] = {remaining, newNode};
                return;
            }

            auto& edge = current->children[firstChar];
            string edgeStr = edge.first;
            PatriciaNode* childNode = edge.second;

            int matchLen = getCommonPrefixLength(remaining, edgeStr);

            // Case 1: The remaining string matches the edge exactly
            if (matchLen == edgeStr.length() && matchLen == remaining.length()) {
                childNode->isEndOfWord = true;
                return;
            }
            // Case 2: The remaining string is a prefix of the edge
            // We need to split the edge
            else if (matchLen < edgeStr.length()) {
                PatriciaNode* splitNode = new PatriciaNode();
                
                // The split node takes the remaining part of the original edge
                string remainingEdgeStr = edgeStr.substr(matchLen);
                splitNode->children[remainingEdgeStr[0]] = {remainingEdgeStr, childNode};
                
                // If there's more of our new word to insert, add it to the split node
                if (matchLen < remaining.length()) {
                    PatriciaNode* newWordNode = new PatriciaNode();
                    newWordNode->isEndOfWord = true;
                    string remainingInsert = remaining.substr(matchLen);
                    splitNode->children[remainingInsert[0]] = {remainingInsert, newWordNode};
                } else {
                    splitNode->isEndOfWord = true; // The split node is the end of the new word
                }

                // Update the current node's edge to point to the split node
                current->children[firstChar] = {edgeStr.substr(0, matchLen), splitNode};
                return;
            }
            // Case 3: The edge is a prefix of the remaining string
            else {
                remaining = remaining.substr(matchLen);
                current = childNode;
            }
        }
    }

    // Search for a word
    bool search(const string& word) {
        PatriciaNode* current = root;
        string remaining = word;

        while (!remaining.empty()) {
            char firstChar = remaining[0];

            if (current->children.find(firstChar) == current->children.end()) {
                return false;
            }

            auto& edge = current->children[firstChar];
            string edgeStr = edge.first;
            PatriciaNode* childNode = edge.second;

            int matchLen = getCommonPrefixLength(remaining, edgeStr);

            // If it doesn't match the whole edge, word doesn't exist
            if (matchLen < edgeStr.length()) {
                return false;
            }

            remaining = remaining.substr(matchLen);
            current = childNode;
        }

        return current->isEndOfWord;
    }

    // Delete a word (Simplified: marks as non-word and prunes if leaf)
    bool remove(const string& word) {
        return removeHelper(root, word);
    }

private:
    bool removeHelper(PatriciaNode* node, string remaining) {
        if (remaining.empty()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return node->children.empty(); // Return true if this node can be deleted
        }

        char firstChar = remaining[0];
        if (node->children.find(firstChar) == node->children.end()) {
            return false;
        }

        auto& edge = node->children[firstChar];
        string edgeStr = edge.first;
        PatriciaNode* childNode = edge.second;

        int matchLen = getCommonPrefixLength(remaining, edgeStr);

        // If it doesn't strictly match the path, word isn't in tree
        if (matchLen != edgeStr.length()) {
            return false;
        }

        bool shouldDeleteChild = removeHelper(childNode, remaining.substr(matchLen));

        if (shouldDeleteChild) {
            delete childNode;
            node->children.erase(firstChar);

            // Path compression (Merging): If current node is not end-of-word 
            // and has exactly 1 child left, merge it.
            if (!node->isEndOfWord && node->children.size() == 1 && node != root) {
                // Return true so the parent merges this node
                return true;
            }
            // If current node has no children left and is not end of word, delete it
            return !node->isEndOfWord && node->children.empty();
        }

        // Logic to compress if a child deletion left this node with 1 child
        if (!node->isEndOfWord && node->children.size() == 1 && node != root) {
            auto it = node->children.begin();
            string onlyEdgeStr = it->second.first;
            PatriciaNode* onlyChildNode = it->second.second;

            // Merge edge
            node->children.clear();
            node->children[onlyEdgeStr[0]] = {edgeStr + onlyEdgeStr, onlyChildNode};
        }

        return false;
    }
};

int main() {
    PatriciaTrie ptrie;

    // Insert words
    cout << "=== INSERTING ===" << endl;
    ptrie.insert("romane");
    ptrie.insert("romanus");
    ptrie.insert("romulus");
    ptrie.insert("rubens");
    ptrie.insert("ruber");
    ptrie.insert("rubicon");
    cout << "Words inserted successfully.\n" << endl;

    // Search words
    cout << "=== SEARCHING ===" << endl;
    cout << "Search 'romane': " << (ptrie.search("romane") ? "Found" : "Not Found") << endl;
    cout << "Search 'romanus': " << (ptrie.search("romanus") ? "Found" : "Not Found") << endl;
    cout << "Search 'roman': " << (ptrie.search("roman") ? "Found (Prefix exists)" : "Not Found") << endl;
    cout << "Search 'rubicon': " << (ptrie.search("rubicon") ? "Found" : "Not Found") << endl;
    cout << "Search 'apple': " << (ptrie.search("apple") ? "Found" : "Not Found") << endl << endl;

    // Delete words
    cout << "=== DELETING ===" << endl;
    cout << "Removing 'romanus'..." << endl;
    ptrie.remove("romanus");
    cout << "Search 'romanus': " << (ptrie.search("romanus") ? "Found" : "Not Found") << endl;
    cout << "Search 'romane': " << (ptrie.search("romane") ? "Found" : "Not Found") << endl; // Should still exist

    return 0;
}