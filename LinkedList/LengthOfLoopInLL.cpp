#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d1,Node* n){
        data =d1;
        next = n;
    }
};

int LengthOfLoop(Node* head){
    Node* fast = head;
    Node* slow = head;
    int cnt =1;
    while(fast!=NULL && fast->next!=NULL){
        fast =fast->next->next;
        slow=slow->next;
        if(slow==fast){
            Node* temp = slow->next;
            while(temp!=slow){
                cnt++;
                temp=temp->next;
            }
            return cnt;
        }
    }
    return 0;
};