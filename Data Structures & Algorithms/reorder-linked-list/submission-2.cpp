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
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next=NULL;

        ListNode*prev=NULL;
        ListNode*curr=second;
        while(curr!=NULL){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        second=prev;

        while(head!=NULL && second!=NULL){
            ListNode*temp1=second->next;
            ListNode*temp2=head->next;
            head->next=second;
            head=head->next;
            head->next=temp2;
            second=temp1;
            head=head->next;
        }
        return;
    }
};
