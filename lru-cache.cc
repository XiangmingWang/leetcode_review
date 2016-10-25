//https://leetcode.com/problems/lru-cache/
#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
      auto iter = lru_map_.find(key);
        if (iter == lru_map_.end()) return -1;
      lru_list_.splice(lru_list_.begin(), lru_list_, iter->second);
      return iter->second->second;
    }
    
    void set(int key, int value) {
          auto iter = lru_map_.find(key);
      if (iter != lru_map_.end()) {
         iter->second->second = value;
         lru_list_.splice(lru_list_.begin(), lru_list_, iter->second);
         return;
      }
      if (capacity_ == lru_map_.size()) {
         auto list_iter = lru_list_.end();
         --list_iter;
         lru_map_.erase(list_iter->first);
         list_iter->first = key;
         list_iter->second = value;
         lru_list_.splice(lru_list_.begin(), lru_list_, list_iter);
      } else {
         lru_list_.push_front(make_pair(key, value));
      }
      lru_map_[key] = lru_list_.begin();
    }

private:
   size_t capacity_;
   unordered_map<int, list<pair<int, int>>::iterator> lru_map_;
   list<pair<int, int>> lru_list_;
};
int main() {
   LRUCache cache(3);
   int v[] = {1,2,3,4,5,6,7};
   for (auto i : v) {
      cache.set(i, i);
   }
}
