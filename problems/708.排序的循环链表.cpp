class Node {
public:
    int val;
    Node* next;
    Node() {}
    Node(int _val) {
        val = _val;
        next = nullptr;
    }
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    /*
    3种插入情况：
        1) cur.val < x < cur.next.val 顺序插入 
        2) 插入点为为序列的边界跳跃点：
            如 3->4->1 插入5，这样 1(cur->next)<4(cur)<5(x) 4为插入点的前驱节点；这种情况表示x比最大值都大
            如 3->4->1 插入0，这样 0(x)<1(cur->next)<4(cur) 4为插入点的前驱节点；这种情况表示x比最小值都小
    */
    Node* insert(Node* head, int insertVal) {
        if(!head){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }       
        Node* cur = head;
        while(cur->next != head){
            //cur为边界点
            if(cur->next->val < cur->val){
                if(insertVal > cur->val) break;// x比最大值都大
                if(insertVal < cur->next->val) break;// x比最小值都小
            }
            // 顺序插入x中升序序列中
            if(cur->val <= insertVal && cur->next->val >= insertVal) break;
            cur = cur->next;
        }
        // 将x插入到cur与cur->next之间
        cur->next = new Node(insertVal,cur->next);
        return head;
    }
};