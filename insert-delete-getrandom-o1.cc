//https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m_.find(val) != m_.end()) return false;
		m_[val] = array_.size();
		array_.push_back(val);
		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
       	if (m_.find(val) == m_.end()) return false;
		int last = array_[array_.size()-1];
		m_[last] = m_[val];
		array_[m_[val]] = last;
		array_.pop_back();
		m_.erase(val);
		return true; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return array_[rand()%array_.size()];
    }
private:
	vector<int> array_;
	unordered_map<int, int> m_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
