## PRACTICAL 6

**Trie**
* Trie is a tree-based data structure that stores strings efficiently by sharing common prefixes.
* If these words(hello and help), they share first three letters('h', 'e', 'l'), this is to avoid repeading letters and saves memory.
* If the word "help" to be deleted we  should only delete letter "p" not the whole word because it shares first 3 letters.

**Time Complexity:**: O(k)

![alt text](/assets/1.png)

## PATRICIA Trie

Path Compression: instead of storing one letter per node, it group the letter into chunks, if there are no other words connected to it.

Fast Searching: Because strings are compressed onto edges, searching is faster. 

Splitting chunks to add word: If an edge holds "romanus" and you want to insert "romane", the tree figures out they share "roman". It splits the edge into "roman", with two branches branching off for "us" and "e".

**Time Complexity**:  O(k)

![2 ](/assets/2.png)


## Manachar's Algorithm

* The # Trick: It puts a symbol like # between every letter (e.g., aba => #a#b#a#). This makes every palindrome odd-numbered, so the algorithm only has to look for one type of "middle."

* The Mirror Shortcut: If big palindrome is found, the algorithm knows the right side is a mirror image of the left. Instead of re-scanning letters it has already seen, it just "copies" the symmetry from the left side to the right. 

**Time Complexity**:  O(n)

![alt text](/assets/3.png)


**Reflection**

Though its is hard to understand the code implementation of every algorithm, I can figure out what is happpening inside and how it is working. 
