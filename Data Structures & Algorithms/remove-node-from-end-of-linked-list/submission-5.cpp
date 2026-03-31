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
        ListNode* traverse=head;
        while(traverse!=NULL){
            len++;
            traverse=traverse->next;
        }
        int ele = len-n;
        if(ele==0){return head->next;}
        ListNode*prev=NULL;
        ListNode*curr=head;

        while(ele>0){
            prev=curr;
            curr=curr->next;
            ele--;
        }
        prev->next=curr->next;
        return head;
    }
};
