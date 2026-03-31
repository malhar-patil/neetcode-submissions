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
        int len=0;
        ListNode* traverse = head;
        while(traverse!=NULL){
            len++;
            traverse=traverse->next;
        }
        int count = len-n;
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(count!=0){
            count--;
            prev=curr;
            curr=curr->next;
        }
        if(prev==NULL){return head->next;}
        prev->next=curr->next;
        curr->next=NULL;
        return head;
    }
};
