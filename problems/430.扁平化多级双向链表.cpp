/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    // 深度优先搜索函数
    Node* dfs(Node* head){
        if(!head) return nullptr; // 若当前节点为空，直接返回 nullptr
        auto next = head->next; // 记录当前节点的下一个节点，因为在展开子链表时会改变 head->next
        if(head->child){ // 若当前节点有子链表
            auto child_tail = dfs(head->child);// 递归展开子链表，得到子链表的尾节点
            // 将子链表插入到当前节点后面
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;// 将当前节点的 child 指针置为空
             // 若当前节点的下一个节点不为空，则将子链表的尾节点连接上当前节点下一个节点
            if(next){
                child_tail->next = next;
                next->prev = child_tail;
            }else{
                return child_tail;// 若当前节点的下一个节点为空，返回子链表的尾节点
            }
        }
        auto tail = dfs(next);// 若当前节点没有子链表，则继续递归下一个节点
        // 若下一个节点为空，则返回当前节点
        // 否则返回下一个节点，使得当前节点的下一个节点连上之后的链表
        return tail == nullptr ? head:tail;
    }
};
// @lc code=end


//题目
/**
 * 你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 子指针 。
 * 这个子指针可能指向一个单独的双向链表，也包含这些特殊的节点。
 * 这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 多层数据结构 。
 * 
 * 给定链表的头节点 head ，将链表 扁平化 ，以便所有节点都出现在单层双链表中。
 * 让 curr 是一个带有子列表的节点。子列表中的节点应该出现在扁平化列表中的 curr 之后 和 curr.next 之前 。
 * 
 * 返回 扁平列表的 head 。列表中的节点必须将其 所有 子指针设置为 null 。
 * 
 * 以 示例 1 为例：
 * 
 *  1---2---3---4---5---6--NULL
 *          |
 *          7---8---9---10--NULL
 *              |
 *              11--12--NULL
 * [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
*/

