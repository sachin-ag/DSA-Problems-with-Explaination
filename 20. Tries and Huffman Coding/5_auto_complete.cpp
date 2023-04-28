#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* Given n number of words and an incomplete word w. 
You need to auto-complete that word w.

That means, find and print all the possible words 
which can be formed using the incomplete word w.

Note : Order of words does not matter. */

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void autoComplete(TrieNode* root, string pattern, string word) {
        if (pattern.size() == 0) {
            if (root -> isTerminal == true) {
                cout << word << endl;
            }
            for (int i=0; i<25; i++) {
                if (root -> children[i] != NULL) {
                    autoComplete(root -> children[i], pattern, word + root -> children[i] -> data);
                }
            }
            return;
        }
        int index = pattern[0] - 'a';
        if (root -> children[index] == NULL) {
            return;
        } else {
            autoComplete(root -> children[index], pattern.substr(1), word);
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        // first we will need to insert the given words
        for (int i=0; i<input.size(); i++) {
            insertWord(input[i]);
        }
        // now we call the function to search and print the words
        autoComplete(root, pattern, pattern);
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}