// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

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
        ListNode *mid = findMidList(head);
        
        ListNode *h1 = head;
        ListNode *h2 = mid->next;
        mid->next = nullptr; //断成两个链表
    
        h2 = reverseList(h2);

        mergeList(h1, h2);
        
    }

    //返回中间节点
    ListNode* findMidList(ListNode* head){

        ListNode *slow = head, *fast = head;
        /////////////////
        //！！！！！！！//
        //！！！坑！！！// 判断 fast->next->next之前得先判断fast->next，否则会runtime_error
        //！！！！！！！//
        /////////////////
        while(fast->next&&slow->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //反转节点
    ListNode* reverseList(ListNode* head){
        if(head == nullptr){
            return head;
        }
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while(cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        } 
        return pre;
    }

    //穿插合并链表
    void mergeList(ListNode* h1, ListNode* h2){
        ListNode *tmp1 ,*tmp2;
        while(h1 && h2){
            //  h1 >= h2
            tmp1 = h1->next;
            tmp2 = h2->next;

            h1->next = h2;
            h1 = tmp1;
            h2->next = h1;
            h2 = tmp2;
        }
    }
};
// @lc code=end

//题目
/**
 * 
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * L0 → L1 → … → Ln - 1 → Ln
 * 请将其重新排列后变为：
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 * 
 * 
*/