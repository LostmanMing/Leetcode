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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        auto p = lists[0];
        for(int i = 1;i < lists.size();i++){
            p = merage(p,lists[i]);
        }
        return p;
    }
    ListNode* merage(ListNode* l,ListNode* r){
        ListNode* dummy = new ListNode();
        auto p = dummy;
        while(l && r){
            if(l->val < r->val){
                p->next = l;
                l = l->next;
                p = p->next;
            }else{
                p->next = r;
                r = r->next;
                p = p->next;
            }
        }
        p->next = l ? l : r;
        return dummy->next;
    }
};
// @lc code=end

