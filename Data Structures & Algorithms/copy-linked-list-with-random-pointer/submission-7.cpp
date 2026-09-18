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
        if(head == NULL) {
            return NULL;
        }
        Node* iter = head;

        while(iter!=NULL){
            Node* temp = iter->next;
            Node* newNode = new Node(iter->val);
            iter->next = newNode;
            newNode->next = temp;
            iter = newNode->next;
        }

        Node* prev = head;
        Node* curr = head->next;

        while(curr!=NULL){
            Node* temp = curr->next;

            if(curr->next!=NULL){
                curr->next = curr->next->next;
            }   
            else{
                curr->next = NULL;
            }
            
            if(prev->random!=NULL){
                curr->random = prev->random->next;
            }
            else{
                curr->random = NULL;
            }

            if(temp != NULL){
                prev = temp;
                curr = temp->next;
            }
            else{
                break;
            }

        }

        return head->next;
    }
};
