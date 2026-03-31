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
    int getLength(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    pair<ListNode*, ListNode*> reverse(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(k>0){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
            k--;
        }
        return {prev,curr};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        int count = len/k;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        pair<ListNode*, ListNode*> p = {NULL,NULL};
        while(count>0){
            ListNode* nextNode = head;
            p = reverse(head,k);
            temp->next = p.first;
            temp=nextNode;
            head=p.second;
            count--;
        }
        if(len%k!=0){
            temp->next = p.second;
        }
        return ans->next;
    }
};
