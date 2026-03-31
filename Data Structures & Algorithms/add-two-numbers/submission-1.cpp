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
        int carry =0;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(l1!=NULL && l2!=NULL){
            sum = (carry + l1->val + l2->val)%10;
            carry = (carry+l1->val + l2->val)/10;
            ListNode* newNode = new ListNode(sum);
            temp->next=newNode;
            temp=temp->next;
            l1=l1->next;l2=l2->next;
        }

        while(l1!=NULL){
            sum = (carry + l1->val)%10;
            carry = (carry+ l1->val)/10;
            ListNode* newNode = new ListNode(sum);
            temp->next=newNode;
            temp=temp->next;
            l1=l1->next;
        }

        while(l2!=NULL){
            sum = (carry + l2->val)%10;
            carry = (carry+l2->val)/10;
            ListNode* newNode = new ListNode(sum);
            temp->next=newNode;
            temp=temp->next;
            l2=l2->next; 
        }
        if(carry>0){
            ListNode* newNode = new ListNode(carry);
            temp->next=newNode;
            temp=temp->next;  
        }
        return ans->next;
    }
};
