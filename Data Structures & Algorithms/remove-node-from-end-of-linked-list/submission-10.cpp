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
        int length = 0;
        ListNode* iter = head;
        while(iter!=NULL){
            iter = iter->next;
            length++;
        }
        n = length - n;

        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL && n>0){
            ListNode* temp = curr->next;
            prev = curr;
            curr = temp;
            n--;
        }
        if(prev == NULL){
            return head->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};
