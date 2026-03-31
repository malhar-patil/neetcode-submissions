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
        Node* traverse = head;

        while(traverse!=NULL){
            Node* newNode = new Node(traverse->val);
            m[traverse] = newNode;
            traverse=traverse->next;
        }

        for(auto iter=m.begin();iter!=m.end();iter++){
            if(iter->first->next==NULL){
                (iter->second)->next = NULL;
            }
            else{
                (iter->second)->next = m[(iter->first)->next];
            }
            if(iter->first->random==NULL){
                (iter->second)->random = NULL;
            }
            else{
                (iter->second)->random = m[(iter->first)->random];
            }
        }
        return m[head];
    }
};
