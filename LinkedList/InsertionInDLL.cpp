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

Node* InsertionInEnd(Node* head,int k){
    Node*temp =head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(k);
    newNode->prev = temp;
    newNode->next = NULL;
    temp-> next = newNode;

    return head;

}

int main(){

}