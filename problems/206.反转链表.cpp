/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* left = nullptr;
        ListNode* right = head;
        while (right != nullptr){
            ListNode* next = right->next;   //保存右指针的下一个节点
            right->next = left;             //翻转指针
            left = right;                   //右移左指针
            right = next;                   //右移右指针
        }
        return left;
    }
};
// @lc code=end

//题目
/**
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
*/