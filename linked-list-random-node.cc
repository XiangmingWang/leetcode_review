//https://leetcode.com/problems/linked-list-random-node/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
       head_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
      int select = head_->val;
       ListNode* now = head_->next;
      int count = 1;
      while(now) {
         ++count;
         if (rand() % count == 0) select = now->val;
         now = now->next;
      }
      return select;
    }
private:
   ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
