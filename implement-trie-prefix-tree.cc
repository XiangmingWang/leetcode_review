//https://leetcode.com/problems/implement-trie-prefix-tree/
#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    char c_;
   bool is_word_;
   TrieNode* children_[26];
    // Initialize your data structure here.
    TrieNode() {
      c_ = 0;
      is_word_ = false;
      memset(children_, 0, sizeof(TrieNode*) * 26);
    }
    TrieNode(char c) {
      c_ = c;
      is_word_ = false;
      memset(children_, 0, sizeof(TrieNode*) * 26);
    }

};

class Trie {
public:
    Trie() {
        root_ = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
      if (word.empty()) return;
      TrieNode* tmp = root_;
      for (const char& c : word) {
              if (tmp->children_[c-'a'] == nullptr) {
            tmp->children_[c-'a'] = new TrieNode(c);
         }
         tmp = tmp->children_[c-'a'];
      }
      tmp->is_word_ = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
      TrieNode* tmp = root_;
      for (const char& c : word) {
         if (tmp->children_[c-'a'] == nullptr) return false;
         tmp = tmp->children_[c-'a'];
      }
      return tmp->is_word_;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
       TrieNode* tmp = root_;
      for (const char& c : prefix) {
         if (tmp->children_[c-'a'] == nullptr) return false;
         tmp = tmp->children_[c-'a'];
      }
      return true;
    }

private:
    TrieNode* root_;
};

// Your Trie object will be instantiated and called as such:
int main() {
   Trie trie;
   trie.insert("somestringkey");
   trie.insert("keyestringkey");
   //trie.insert("key");
   cout << "starts:"<<trie.startsWith("key") << endl;
   cout << trie.search("key") << endl;
}
