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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
    
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* newList = slow->next;
        slow->next=NULL;
        newList = reverse(newList);

        ListNode* dummy=head;
        while(newList!=NULL){
            ListNode* temp1 = dummy->next;
            ListNode* temp2 = newList->next;
            dummy->next=newList;
            dummy=dummy->next;
            dummy->next=temp1;
            newList=temp2;
            dummy=dummy->next;
        }
    }
};
// 0 1 2 3 
// 6 5 4