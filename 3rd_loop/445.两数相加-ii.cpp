/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        int rest = 0;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        while(l1 || l2 || rest!=0){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int num = n1 + n2 + rest;

            ListNode* next = new ListNode(num % 10);
            rest = num / 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

            res->next = next;
            res = res->next;
        }
        return reverse(dummy->next);
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
};
// @lc code=end

