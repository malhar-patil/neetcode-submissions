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
        if(lists.size()<=0){
            return NULL;
        }

        ListNode* ans = new ListNode();
        ListNode* list1 = lists[0];

        for(int i=1;i<lists.size();i++){
            ListNode* traverse = ans;
            ListNode* list2 = lists[i];
            while(list1!=NULL && list2!=NULL){
                if(list1->val<=list2->val){
                    ListNode* temp=list1->next;
                    traverse->next=list1;
                    list1=temp;
                    traverse=traverse->next;
                }
                else{
                    ListNode* temp=list2->next;
                    traverse->next=list2;
                    list2=temp;
                    traverse=traverse->next;  
                }
            }
            if(list1!=NULL){
                traverse->next=list1;
            }
            if(list2!=NULL){
                traverse->next=list2;
            }
            list1 = ans->next;
        }
        return ans->next;
    }
};
