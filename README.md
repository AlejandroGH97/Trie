# Trie Structure

Trie structure capable of building from a file. The build file must have each word sepparated by a line break.

## Methods
    - getRoot();
    - insert(string word, unsigned int pdir, unsigned int offset);
    - void deleteWord(string word);
    - prefix(string word);
    - search(string word);
    - print();
    - print(Node* node, int l);
    - build(string file);
