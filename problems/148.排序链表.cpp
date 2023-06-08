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
// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    // 切分链表，返回右半部分的起始节点
    ListNode* cut(ListNode* head, int n){    //
        auto p = head;
        while(--n && p){
            p = p->next;
        }
        if(!p) return nullptr;// 若链表已经结束，返回空指针表示切分失败
        auto next = p->next;
        p->next = nullptr;// 将切分位置处的节点与后面的节点断开
        return next;
    }
    // 合并两个有序链表
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode dummy;  //虚拟头结点简化操作。存放合并后的链表
        auto p = &dummy;  
        while(l && r){
            if(l->val < r->val){
                p->next = l;  // 将较小的节点链接到合并后的链表上
                p = p->next;
                l = l->next;
            }else{
                p->next = r;
                p = p->next;
                r = r->next;
            }
        }
        p->next = l ? l : r;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        auto p = head;
        auto size = 0;
        while(p){
            size++;
            p = p->next;
        }
        for(int len = 1; len < size; len <<= 1){   // 外层循环，每次长度翻倍
            auto cur = dummy.next; // 指针 cur 指向当前链表的头节点
            auto tail = &dummy; // 指针 tail 后合并排序后链表
            while(cur){
                auto left = cur;
                auto right = cut(left, len);
                cur = cut(right, len); // 更新 cur 指针到下一轮切分的起始位置
                tail->next = merge(left,right);
                while(tail->next){
                    tail =tail->next;
                }
            }
        }
        return dummy.next;
    }
};
// @lc code=end

//题目
/**
 * 
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 示例 1：
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 */