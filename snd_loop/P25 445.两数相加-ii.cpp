// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

// 示例1：



// 输入：l1 = [7,2,4,3], l2 = [5,6,4]
// 输出：[7,8,0,7]
// 示例2：

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[8,0,7]
// 示例3：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]
 

// 提示：

// 链表的长度范围为 [1, 100]
// 0 <= node.val <= 9
// 输入数据保证链表代表的数字无前导 0
 

// 进阶：如果输入链表不能翻转该如何解决？

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
struct  ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int rest = 0;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        while(l1 || l2 || rest != 0){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int num = n1 + n2 + rest;
            ListNode* next = new ListNode(num % 10);
            rest = num / 10;
            res->next = next;
            res = res->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return reverse(dummy->next);
    }
    ListNode* reverse(ListNode* head){
        ListNode* l = nullptr;
        ListNode* r = head;
        while(r){
            ListNode* next = r->next;
            r->next = l;
            l = r;
            r = next;
        }
        return l;
    }
};
// @lc code=end

