/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 *  */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode();//创建一个虚拟头节点指向链表的头
        dummyhead->next = head;
        ListNode* left = dummyhead;//定义指针left和right,初始值指向虚拟头节点
        ListNode* right = dummyhead;
        for(int i = 0;i < n + 1;i++){
            right = right->next;    //q指针移动n+1次
        }
        while(right){
            left = left->next;
            right = right->next;
        }
        ListNode* delNode = left->next; //记录要删除的节点，并将其delete避免内存泄露
        left->next = left->next->next;
        delete delNode;
        return dummyhead->next;    //返回链表头，使用虚拟节点的下一个节点是为了避免头结点被删除的情况
    }
};
// @lc code=end

//题目
/**
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 示例 1：
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 
*/

/*
采取双重遍历肯定是可以解决问题的，但题目要求我们一次遍历解决问题，那我们的思路得发散一下。

我们可以设想假设设定了双指针 p 和 q 的话，当 q 指向末尾的 NULL，p 与 q 之间相隔的元素个数为 n 时，那么删除掉 p 的下一个指针就完成了要求。

设置虚拟节点 dummyHead 指向 head
设定双指针 p 和 q，初始都指向虚拟节点 dummyHead
移动 q，直到 p 与 q 之间相隔的元素个数为 n
同时移动 p 与 q，直到 q 指向的为 NULL
将 p 的下一个节点指向下下个节点

*/