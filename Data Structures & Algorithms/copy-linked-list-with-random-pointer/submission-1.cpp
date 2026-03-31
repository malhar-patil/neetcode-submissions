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
        unordered_map<Node*,Node*> m;

        Node* iter = head;
        Node* tempHead = head;
        int index=0;
        while(iter!=NULL){
            Node* newNode = new Node(iter->val);
            m[iter] = newNode;
            iter=iter->next;
        }

        while(head!=NULL){
            m[head]->random = m[head->random];
            m[head]->next = m[head->next];
            head=head->next;
        }
        return m[tempHead];
    }
};
