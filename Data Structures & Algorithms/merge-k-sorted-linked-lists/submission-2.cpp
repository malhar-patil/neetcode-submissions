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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                ListNode*temp=l1->next;
                ans->next = l1;
                l1 = temp;
                ans=ans->next;
            }
            else{
                ListNode*temp=l2->next;
                ans->next = l2;
                l2 = temp;
                ans=ans->next;  
            }
        }

        if(l1!=NULL){
            ans->next=l1;
        }
        if(l2!=NULL){
            ans->next=l2;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1001);
        ListNode* temp = ans;

        for(int i=0;i<lists.size();i++){
            merge(temp, lists[i]);
        }
        return ans->next;

    }
};
