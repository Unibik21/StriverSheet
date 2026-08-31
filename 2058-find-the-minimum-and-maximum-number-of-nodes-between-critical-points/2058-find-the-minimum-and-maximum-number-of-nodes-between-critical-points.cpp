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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>crit;
        ListNode* prev = NULL;
        ListNode* next = head->next;
        int dist = 1;
        while(head){
            if(prev && next){
                if(prev->val<head->val && next->val<head->val){
                    crit.push_back(dist);
                }
                else if(prev->val>head->val && next->val>head->val){
                    crit.push_back(dist);
                }
            }
            dist++;
            prev = head;
            head=head->next;
            if(head->next)next=head->next;
            else break;
        }

        if(crit.size()<2){
            return {-1,-1};
        }

        int maxi = crit[crit.size()-1]-crit[0];
        int mini = INT_MAX;

        for(int i=0;i<crit.size()-1;i++){
            mini = min(mini,crit[i+1]-crit[i]);
        }

        return {mini,maxi};
    }
};