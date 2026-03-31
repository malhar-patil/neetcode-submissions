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
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);
        if(n==1){
            head = head->next;
            head = reverseList(head);
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        int target = 1;
        while(target<n && curr!=NULL){
            prev=curr;
            curr=curr->next;
            target++;
        }
        prev->next=curr->next;
        curr->next=NULL;

        head = reverseList(head);
        return head;

    }
};
