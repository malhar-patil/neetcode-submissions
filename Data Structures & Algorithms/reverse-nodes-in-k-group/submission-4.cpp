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
    pair<ListNode*, ListNode*> reverse(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 0;

        while(curr!=NULL && cnt < k){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp; 
            cnt++;
        }
        return {prev,curr};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* iter = head;
        while(iter!=NULL){
            iter = iter->next;
            len++;
        }

        ListNode* res = new ListNode();
        iter = res;
        while(len >= k){
            ListNode*temp=head;
            pair<ListNode*, ListNode*> p = reverse(head, k);
            iter->next = p.first;
            iter = temp;
            head = p.second;
            len-=k;
        }
        iter->next = head;
        return res->next;
    }
};
