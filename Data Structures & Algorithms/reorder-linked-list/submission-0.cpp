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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(!(fast==nullptr) && !(fast->next==nullptr)){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=slow->next=nullptr;

        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode* curr1=head;
        ListNode* curr2=prev;

        while(curr2){
            ListNode* temp1=curr1->next;
            curr1->next=curr2;
            curr1=temp1;
            ListNode* temp2=curr2->next;
            curr2->next=curr1;
            curr2=temp2;
        }
    }
};
