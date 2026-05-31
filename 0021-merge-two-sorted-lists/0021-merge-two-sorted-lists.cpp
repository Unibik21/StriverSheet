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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;

        while(head1 && head2){
            if(head1->val<head2->val){
                head->next=head1;
                head1=head1->next;
            }
            else{
                head->next = head2;
                head2=head2->next;
            }
            head=head->next;
        }
        while(head1){
            head->next=head1;
            head1=head1->next;
            head = head->next;
        }
        while(head2){
            head->next = head2;
            head2=head2->next;
            head = head->next;
        }

        return temp->next;
    }
};