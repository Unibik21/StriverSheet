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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        int len = 1;
        ListNode* temp = head;

        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        k=k%len;
        int s = len-k;

        ListNode* tail = head;
        for(int i=1;i<s;i++){
            tail=tail->next;
        }

        temp->next = head;
        ListNode* newHead = tail->next;
        tail->next=NULL;

        return newHead;
    }
};