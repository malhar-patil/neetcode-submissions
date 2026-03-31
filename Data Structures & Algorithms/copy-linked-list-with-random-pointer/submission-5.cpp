/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* iter = head;
        while(iter!=NULL){
            Node* newNode = new Node(iter->val);
            m[iter] = newNode;
            iter=iter->next;
        }

        iter = head;
        while(iter!=NULL){
            m[iter]->next = m[iter->next];
            m[iter]->random = m[iter->random];
            iter = iter->next;
         }

        return m[head];
    }
};
