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
        ListNode* res = new ListNode();
        ListNode* iter = res;

        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                ListNode* temp = l1->next;
                iter->next = l1;
                iter = iter->next;
                l1 = temp;
            }
            else{
                ListNode* temp = l2->next;
                iter->next = l2;
                iter = iter->next;
                l2 = temp; 
            }
        }
        if(l1!=NULL){
            iter->next = l1;
        }
        if(l2!=NULL){
            iter->next = l2;
        }

        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){return NULL;}
        if(lists.size() == 1){return lists[0];}
        ListNode* res = NULL;
        for(int i=0;i<lists.size();i++){
            res = merge(res, lists[i]);
        }
        return res;
    }
};
