/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                auto node = dummy;
                while(node != slow){
                    node = node->next;
                    slow = slow->next;
                }
                return node;
            }
        }
        return nullptr;
    }
};
// @lc code=end

