//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
      m_[val].push(array_.size());
      array_.push_back(val); 
      return m_[val].size() == 1;       
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m_.find(val) == m_.end() || m_[val].empty()) return false;
      int rm_idx = m_[val].top();
      m_[val].pop();
      if (array_.size() - 1 != rm_idx) {
         int last = array_.back();
         array_[rm_idx] = last;
         m_[last].pop();
         m_[last].push(rm_idx);
      }
      array_.pop_back();
      return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
       return array_[rand()%array_.size()]; 
    }

private:
   unordered_map<int, priority_queue<int>> m_;
   vector<int> array_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

