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
        if(head->next == NULL){
            return NULL;
        }
        int len = 0;

        ListNode* iter = head;
        while(iter!=NULL){
            iter=iter->next;
            len++;
        }
        // cout<<len<<endl;
        int nodeToRemove = len-n;
        int present = 0;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(present < nodeToRemove){
            ListNode* temp = curr->next;
            prev=curr;
            curr=temp;
            present++;
        }
        // cout<<prev->val<<" "<<curr->val<<endl;
        if(nodeToRemove == 0 || prev == NULL){
            return head->next;
        }
        prev->next = curr->next;
        return head;
    }
};
