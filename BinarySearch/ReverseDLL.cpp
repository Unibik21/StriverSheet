#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d1,Node* n,Node* p){
        data =d1;
        next = n;
        prev = p;
    }
    Node(int d1){
        data =d1;
        next = NULL;
        prev = NULL;
    }
};

Node* reverseDLL(Node* head){

    Node* curr = head;
    Node* back = NULL;

    while(curr!=NULL){
        back = curr->prev;
        curr->prev = curr->next;
        curr->next = back;

        curr=curr->prev;
    }
    return back->prev;
}