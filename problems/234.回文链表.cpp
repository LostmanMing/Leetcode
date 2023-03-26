/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode *mid = findMidList(head);
        
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        //分成两个链表
        mid->next = nullptr;

        l2 = reverseList(l2);

        while(l1 && l2){
            if(l1->val != l2->val){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

    //寻找链表中点
    ListNode *findMidList(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast->next && slow->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //反转链表
    ListNode * reverseList(ListNode*head){
        ListNode *pre = nullptr, *cur = head;
        while(cur){
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end


//题目
/**
 * 
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
 * 如果是，返回 true ；否则，返回 false 。
 * 
 * 示例 1：
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 
*/