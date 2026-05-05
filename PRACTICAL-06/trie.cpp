// Implement the basic trie algorithm and perform the insert, search and deletion operations
#include <iostream>
#include <unordered_map>
using namespace std;

// define a TrieNode class to represent each node in the trie
class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26]; // assuming only lowercase letters a-z
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }   
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // insert a word into the trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            // Calculate index for character (a=0, b=1, ..., z=25)
            int index = c - 'a';
            // If child node doesn't exist, create a new one
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            // move to the child node
            current = current->children[index];
        }
        // mark the end of the word
        current->isEndOfWord = true;
    }

    // search for a word in the trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            // calculate index for character
            int index = c - 'a';
            // if child node doesn't exist, word is not in trie
            if (current->children[index] == nullptr) {
                return false;
            }
            // move to the child node
            current = current->children[index];
        }
        // return true only if current node marks end of a word
        return current->isEndOfWord;
    }

    // delete a word from the trie
    bool remove(const string& word) {
        return removeHelper(root, word, 0);
    }

private:
    bool removeHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                // check if node has any children
                for (int i = 0; i < 26; i++) {
                    if (node->children[i] != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        char c = word[depth];
        int index = c - 'a';
        if (node->children[index] && removeHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;
            // check if node has any children
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    return false;
                }
            }
            return !node->isEndOfWord;
        }
        return false;
    }
};

int main() {
    Trie trie;
    
    // insert words
    trie.insert("hello");
    trie.insert("world");
    trie.insert("help");
    
    // search words
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'help': " << (trie.search("help") ? "Found" : "Not Found") << endl;
    cout << "Search 'hero': " << (trie.search("hero") ? "Found" : "Not Found") << endl;
    
    // delete a word
    cout << "\nDeleting 'help'..." << endl;
    trie.remove("help");
    
    // search again
    cout << "Search 'help': " << (trie.search("help") ? "Found" : "Not Found") << endl;
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    
    return 0;
}