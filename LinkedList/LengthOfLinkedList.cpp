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

int LengthOfLinkedList(Node* head){
    int cnt =0;
    Node* temp = head;

    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}