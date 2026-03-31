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
        if(head==NULL){
            return 0;
        }
        int length=0;
        while(head!=NULL){
            length++;
            head=head->next;
        }
        return length;
    }
    pair<ListNode*,ListNode*> reverseList (ListNode* head, int k){
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nextNode=NULL;
        while(curr!=NULL && k>0){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            k--;
        }
        return {prev,nextNode};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*ans=new ListNode();
        ListNode*returnValue=ans;
        ListNode*temp=head;

        int length = getLength(head);
        int count = length/k;
        while(count>0 && temp!=NULL){
            ListNode*first=temp;
            pair<ListNode*,ListNode*> p = reverseList(temp,k);
            ans->next = p.first;
            ans=temp;
            temp=p.second;
            count--;
        }
        ans->next=temp;
        return returnValue->next;
    }
};
