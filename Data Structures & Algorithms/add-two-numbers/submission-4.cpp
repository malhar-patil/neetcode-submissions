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
    int getLen(ListNode* head){
        int len = 0;
        ListNode* iter = head;

        while(iter!=NULL){
            iter=iter->next;
            len++;
        }

        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // auto&& [list1, len1] = reverseList(l1);
        // auto&& [list2, len2] = reverseList(l2);

        int len1 = getLen(l1);
        int len2 = getLen(l2);

        if(len2 > len1){
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }

        ListNode* ans = new ListNode(-1);
        ListNode* traverse = ans;

        int sum = 0;
        int carry = 0;

        ListNode* iter1 = l1;
        ListNode* iter2 = l2;

        while(iter1!=NULL && iter2!=NULL){
            int total = iter1->val + iter2->val + carry;
            sum = (total) % 10;
            carry = (total)/ 10;

            traverse->next =  new ListNode(sum);
            traverse = traverse->next;

            iter1 = iter1->next;
            iter2 = iter2->next;
        }

        while(iter1!=NULL){
            int total = iter1->val + carry;
            sum = (total) % 10;
            carry = (total)/ 10;

            traverse->next =  new ListNode(sum);
            traverse = traverse->next;

            iter1 = iter1->next;
        }

        if(carry!=0){
            traverse->next =  new ListNode(carry);
        }

        return ans->next;
    }
};
