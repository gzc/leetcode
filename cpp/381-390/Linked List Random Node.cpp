class Solution {
    vector<int> myvec;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        while (head != nullptr) {
            myvec.push_back(head->val);
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return myvec[rand()%myvec.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
