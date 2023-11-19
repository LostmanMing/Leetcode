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
        auto list = head;;
        s.push(list);
        Node * pre = nullptr;
        while(!s.empty()){
            auto top = s.top();
            s.pop();

            if(top == nullptr) return nullptr;

            if(top->next){
                s.push(top->next);
            }
            if(top->child){
                s.push(top->child);
                top->child = nullptr;
            }
            if(pre){
                pre->next = top;
                top->prev = pre;
            }
            pre = top;
        }
        return head;
    }
};
// @lc code=end

