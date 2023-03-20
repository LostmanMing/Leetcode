/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa != pb){
            pa = pa == nullptr ? headB:pa->next;
            pb = pb == nullptr ? headA:pb->next;
        }
        return pa;
    }
};
// @lc code=end

//题目
/**
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
 * 如果两个链表不存在相交节点，返回 null 。
 * 
 * 
*/
/*
设「第一个公共节点」为 node ，「链表 headA」的节点数量为 a ，「链表 headB」的节点数量为 b ，
「两链表的公共尾部」的节点数量为 c ，则有：

头节点 headA 到 node 前，共有 a−c 个节点；
头节点 headB 到 node 前，共有 b−c 个节点；

考虑构建两个节点指针 A​ , B 分别指向两链表头节点 headA , headB ，做如下操作：

指针 A 先遍历完链表 headA ，再开始遍历链表 headB ，当走到 node 时，共走步数为：

a+(b−c)

指针 B 先遍历完链表 headB ，再开始遍历链表 headA ，当走到 node 时，共走步数为：

b+(a−c)

如下式所示，此时指针 A , B 重合，并有两种情况：

a+(b−c)=b+(a−c)

若两链表 有 公共尾部 (即 c>0 ) ：指针 A , B 同时指向「第一个公共节点」node 。
若两链表 无 公共尾部 (即 c=0 ) ：指针 A , B 同时指向 null 。因此返回 A 即可。


*/