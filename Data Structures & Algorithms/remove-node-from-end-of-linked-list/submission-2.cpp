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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left=head;
        ListNode* right=head;
        while(n>0){
            right=right->next;
            n--;
        }
        if(right==nullptr){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        while(right->next){
            left=left->next;
            right=right->next;
        }
        ListNode* temp=left->next;
        left->next=left->next->next;
        delete temp;
        return head;
    }
};
