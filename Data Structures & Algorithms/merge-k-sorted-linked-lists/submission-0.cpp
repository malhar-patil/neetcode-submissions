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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* ans = new ListNode();
        ListNode* firstList=lists[0];

        for(int i=1;i<lists.size();i++){
            ListNode* temp = ans;
            while(firstList!=NULL && lists[i]!=NULL){
                if(firstList->val<=lists[i]->val){
                    temp->next = firstList;
                    temp=temp->next;
                    firstList=firstList->next;
                }
                else{
                    temp->next=lists[i];
                    temp=temp->next;
                    lists[i]=lists[i]->next;
                }
            }

            if(firstList!=NULL){
                temp->next=firstList;
            }

            if(lists[i]!=NULL){
                temp->next=lists[i];
            }
            firstList = ans->next;
        }
        return ans->next;
    }
};
