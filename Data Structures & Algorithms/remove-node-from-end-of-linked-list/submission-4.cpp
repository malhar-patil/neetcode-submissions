/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        // Two pass approach
        int length=0;
        ListNode*temp=head;

        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        int removeNode = length - n;
        if(removeNode == 0){
            return head->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(removeNode>0){
            prev=curr;
            curr=curr->next;
            removeNode--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        return head;
    }
};
