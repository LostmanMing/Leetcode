/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    void reorderList(ListNode* head) {
        auto mid = findMid(head);
        auto l1 = head;
        auto l2 = mid->next;
        mid->next = nullptr;

        l2 = reverse(l2);
        while(l1 && l2){
            auto n1 = l1->next;
            auto n2 = l2->next;
            l1->next = l2;
            l2->next = n1;
            l1 = n1;
            l2 = n2;
        }
    }
    ListNode* reverse(ListNode* head){
        ListNode* l = nullptr;
        ListNode* r = head;
        while(r){
            auto tmp = r->next;
            r->next = l;
            l = r;
            r = tmp;
        }
        return l;
    }
    ListNode* findMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end

