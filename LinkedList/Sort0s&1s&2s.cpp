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
    Node(int d1){
        data =d1;
        next = NULL;
    }
};

Node* sort(Node* head){
    Node* dummy0 = new Node(-1);
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);

    Node* tail0 = dummy0;
    Node* tail1 = dummy1;
    Node* tail2 = dummy2;
    Node* curr = head;

    while(curr){
        if(curr->data==0){
            tail0->next=curr;
            tail0=tail0->next;
        }
        else if(curr->data==1){
            tail1->next=curr;
            tail1=tail1->next;
        }
        else{
            tail2->next=curr;
            tail2=tail2->next;
        }
        curr=curr->next;
    }

    tail0->next = dummy1->next ? dummy1->next : dummy2->next;
    tail1->next = dummy2->next;
    tail2->next=NULL;

    return dummy0->next;

}