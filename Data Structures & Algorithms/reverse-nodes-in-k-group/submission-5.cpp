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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* ans = new ListNode();
        ListNode* ansIter = ans;

        ListNode* iter = head;
        while(iter!=NULL){
            iter = iter->next;
            len++;
        }
        
        ListNode* start = head;
        ListNode* end = head;
        while(len >= k){
            int nodes = 1;
            while(nodes < k){
                end = end->next;
                nodes++;
            }

            ListNode* temp = end->next;
            end->next = NULL;

            ansIter->next = reverse(start);
            ansIter = start;


            start = temp;
            end = temp;
            len -= k;
        }
        if(len != 0){
            ansIter->next = start;
        }
        return ans->next;
    }
};
