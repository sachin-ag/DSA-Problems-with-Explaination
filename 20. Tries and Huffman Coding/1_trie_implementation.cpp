#include <iostream>
using namespace std;
// we optimize a lot of space by using tries
// for ex if we have BE already in trie then BED will take just one more space
// this is its advantage over hashmap even tho time complex. is same
// trie is used for searching words in a dictionary or document (visualize)

class TrieNode {
    public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isTerminal = false; // by default
    }
};

class Trie {
    TrieNode* root;

    public:

    Trie() {
        root = new TrieNode(NULL); // as root has no data in a trie
    }

    // helper function
    void insertWord(TrieNode* root, string word) {
        // base case
        if (word.size() == 0) {
            root -> isTerminal = true;
            return;
        }

        // small calculation
        int index = word[0] - 'a'; // as a is at 0, b at 1, etc. in the array
        TrieNode* child;
        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // recursive call
        insertWord(child, word.substr(1));
    }

    // for user
    void insertWord(string word) {
        insertWord(root, word);
    }

    bool search(TrieNode* root, string word) {
        if ((word.length() == 0) && (root -> isTerminal == true)) {
            return true;
        }
        if ((word.length() == 0) && (root -> isTerminal == false)) {
            return false;
        }
        int index = word[0] - 'a';
        if (root -> children[index] == NULL) {
            return false;
        } else {
            return search(root -> children[index], word.substr(1));
        }
    }

    // for user
    bool search(string word) {
        return search(root, word);
    }

    void remove(TrieNode* root, string word) {
        if (word.size() == 0) {
            root -> isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root -> children[index] == NULL) {
            return; // as word do not exist
        } else {
            child = root -> children[index];
        }
        remove(child, word.substr(1));
        
        // remove child node if it is useless
        // useless means a node with no children and not a terminal
        if (child -> isTerminal == false) {
            for (int i=0; i<26; i++) {
                if (child -> children[i] != NULL) {
                    return; // as a child exists
                }
            }
            // we r out of for loop means node is useless
            delete child;
            root -> children[index] == NULL;
        }
    }

    void remove(string word) {
        remove(root, word);
    }
};

int main () {
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.search("and") << endl;
    t.remove("and");
    cout << t.search("and") << endl;
    cout << t.search("do") << endl;


    return 0;
}