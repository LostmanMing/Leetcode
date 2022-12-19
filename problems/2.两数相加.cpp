/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        //创建虚拟头结点
        ListNode *dummyHead= new ListNode(0),*res=dummy;
        while(l1 || l2 || sum){
            if(l1){sum += l1->val; l1=l1->next;}
            if(l2){sum += l2->val; l2=l2->next;}
            res->next= new ListNode(sum%10);
            res=res->next;
            sum/=10;
        }
        return dummy->next;
    }
};
// @lc code=end

