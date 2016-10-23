#include <iostream>
using namespace std;
//https://leetcode.com/problems/add-and-search-word-data-structure-design/
struct TrieNode {
    char c_;
    TrieNode* children_[26];
    bool is_word_;
    TrieNode() {
        memset(children_, 0, sizeof(TrieNode*) * 26);
        is_word_ = false;
    }
    TrieNode(char c) {
        c_ = c;
        memset(children_, 0, sizeof(TrieNode*) * 26);
        is_word_ = false;
    }
};

class WordDictionary {
private:
    TrieNode* root_;
public:
    WordDictionary() {
        root_ = new TrieNode();
    }
        // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root_);
    }
    bool search(const string& word, const int& start_idx, TrieNode* now_node) {
        for (int idx = start_idx; idx < word.size(); ++idx) {
            const char& c = word[idx];
            if (c == '.') {
                for (int i = 0; i < 26; ++i) {
                    if (now_node->children_[i] != nullptr)
                        if (search(word, idx+1, now_node->children_[i])) return true;
                }
                return false;
            } else {
                if (now_node->children_[c-'a'] == nullptr) return false;
                now_node = now_node->children_[c-'a'];
            }
        }
        return now_node->is_word_;
    }
};

int main() {

}
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
