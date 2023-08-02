// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

 

// 示例 1：


// 输入：head = [1,2,2,1]
// 输出：true
// 示例 2：


// 输入：head = [1,2]
// 输出：false
 

// 提示：

// 链表中节点数目在范围[1, 105] 内
// 0 <= Node.val <= 9
 

// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

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
struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* l1 = head;

        ListNode* mid = findmid(l1);
        ListNode* l2 = mid->next;

        mid->next = nullptr;

        l2 = reverse(l2);

        while(l1 && l2){
            if(l1->val != l2->val) return false;  //值相等，不是节点相等！
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;

    }
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* l = nullptr;
        ListNode* r = head;
        while(r){
            ListNode* n = r->next;
            r->next = l;
            l = r;
            r = n;  
        }
        return l;
    }
};
// @lc code=end

