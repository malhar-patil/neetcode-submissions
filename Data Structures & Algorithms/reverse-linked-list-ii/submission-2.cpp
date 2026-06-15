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
    pair<ListNode*, ListNode*> reverseList(ListNode*& head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* end = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return {prev, end};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beforeL = new ListNode(-501);
        ListNode* tracker = beforeL;
        ListNode* atL = NULL;
        ListNode* atR = NULL;

        ListNode* curr = head;
        int pos = 1;

        while(curr!=NULL){
            if(pos < left){
                beforeL->next = curr;
                beforeL = beforeL->next;
            }
            if(pos == left){
                atL = curr;
            }
            if(pos == right){
                atR = curr;
            }
            curr = curr->next;
            pos++;
        }

        beforeL->next = atR->next;
        atR->next=NULL;

        pair<ListNode*, ListNode*> reverse = reverseList(atL);

        pos = 1;
        ListNode* prev = tracker;
        curr = tracker->next;

        while(pos < left && curr!=NULL){
            cout<<pos<<endl;
            prev = curr;
            curr = curr->next;
            pos++;
        }


        prev->next = reverse.first;
        reverse.second->next = curr;

        return tracker->next;
    }
};