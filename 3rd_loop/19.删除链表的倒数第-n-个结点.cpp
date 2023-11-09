/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode{
//     int val;
//     ListNode* next;
//     ListNode() : val(0),next(nullptr){}
//     ListNode(int x) : val(x),next(nullptr){}
//     ListNode(int x, ListNode* n) : val(x),next(n){}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto fast = dummy;
        auto slow = dummy;
        for(int i = 0;i <= n;i++){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return dummy->next;
    }
};
// @lc code=end

