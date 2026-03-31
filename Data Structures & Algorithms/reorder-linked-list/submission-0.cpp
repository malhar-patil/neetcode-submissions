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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast =head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* secondHalf = slow->next;
        slow->next=NULL;
        secondHalf = reverseList(secondHalf);

        ListNode* node = head;
        while(secondHalf!=NULL){
            ListNode* temp = node->next;
            ListNode* temp2 = secondHalf->next;
            node->next = secondHalf;
            node=node->next;
            node->next=temp;
            secondHalf=temp2;
            node=node->next;
        }
    }
}; // 0, 1, 2, 3,    6,5,4
