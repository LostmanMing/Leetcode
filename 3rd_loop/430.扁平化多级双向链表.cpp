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
#include<stack>
using namespace std;
// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        auto l = head;
        s.push(l);
        Node * pre = nullptr;
        while(!s.empty()){
            auto top = s.top();
            if(top == nullptr) return nullptr;
            s.pop();
            if(top->next){
                s.push(top->next);
            }
            if(top->child){
                s.push(top->child);
                top->child = nullptr;
            }
            if(pre){
                top->prev = pre;
                pre->next = top;
            }
            pre = top;
        }
        return head;
    }
};
// @lc code=end

