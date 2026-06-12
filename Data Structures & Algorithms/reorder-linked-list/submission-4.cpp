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
    void print(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(head->next == NULL){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = list2;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        list2 = prev;
        ListNode* list1 = head;
        print(list1);
        print(list2);
        while(list1 != NULL && list2!=NULL){
            ListNode* temp2 = list2->next;
            ListNode* temp1 = list1->next;
            list2->next = NULL;

            list1->next = list2;
            list1 = list1->next;
            list1->next = temp1;
            list1 = list1->next;

            list2 = temp2;
        }
        return;
    }
};
