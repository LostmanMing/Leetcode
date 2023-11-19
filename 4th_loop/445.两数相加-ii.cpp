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
        ListNode* res = new ListNode(0);
        auto dummy = res;
        while(l1 || l2 || rest > 0){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            int num = n1 + n2 + rest;
            rest = num / 10;

            ListNode* node = new ListNode(num % 10);
            dummy->next = node;
            dummy = dummy->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return reverse(res->next);
    }

    ListNode* reverse(ListNode* head){
        ListNode* l = nullptr;
        ListNode* r = head;

        while(r){
            auto next = r->next;
            r->next = l;
            l = r;
            r = next;
        }
        return l;
    }
};
// @lc code=end

