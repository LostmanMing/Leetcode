// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

 

// 示例 1：


// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 示例 2：


// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目在范围 [0, 5 * 104] 内
// -105 <= Node.val <= 105
 

// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto p = head;
        while(p){
            p = p->next;
            size++;
        }
        for(int len = 1;len < size;len *= 2){
            auto cur = dummy->next;
            auto tail = dummy;
            while(cur){
                auto left = cur;
                auto right = cut(cur,len);
                cur = cut(right,len);
                tail->next  = merage(left,right);
                while(tail->next){
                    tail = tail->next;
                }
            }
        }
        return dummy->next;
    }

    ListNode* cut(ListNode* root, int n){
        auto p = root;
        while(--n && p){
            p = p->next;
        }
        if(!p) return nullptr;
        auto next = p->next;
        p->next = nullptr;
        return next;
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

