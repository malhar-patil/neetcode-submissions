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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* res = new ListNode();
        ListNode* iter = res;

        while(l1!=NULL && l2!=NULL){
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;

            ListNode* newNode = new ListNode(sum);
            iter->next = newNode;
            iter = iter->next;
            l1=l1->next;
            l2=l2->next;
        } 

        while(l1!=NULL){
            sum = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;

            ListNode* newNode = new ListNode(sum);
            iter->next = newNode;
            iter = iter->next;
            l1=l1->next;
        }

        while(l2!=NULL){
            sum = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            
            ListNode* newNode = new ListNode(sum);
            iter->next = newNode;
            iter = iter->next;
            l2=l2->next;
        }

        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            iter->next = newNode;
            iter=iter->next;
        }
        return res->next;
    }
};
