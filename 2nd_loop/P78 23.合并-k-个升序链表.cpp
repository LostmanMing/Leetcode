/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include<vector>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n) return nullptr;
        auto l = lists[0];
        for(int i = 1;i < n;i++){
            l = merage(l,lists[i]);
        }
        return l;
    }
    ListNode* merage(ListNode* l, ListNode* r){
        ListNode* dummy = new ListNode();
        auto p = dummy;
        while(l && r){
            if(l->val < r->val){
                p->next = l;
                p = p->next;
                l = l->next;
            }else{
                p->next = r;
                p = p->next;
                r = r->next;
            }
        }
        p->next = l ? l : r;
        return dummy->next;
    }
};
// @lc code=end

