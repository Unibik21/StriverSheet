#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next=NULL;
    }
};

Node* head = new Node(-1);
Node* temp = head;

void push(int x){
    Node* n = new Node(x);
    temp->next = n;
    temp=n;
}
void pop(){
    Node* tempo = head;
    if(tempo->next==NULL){cout<<"Stack is Empty"; return;}
    while(tempo->next->next!=NULL){
        tempo=tempo->next;
    }
    tempo->next=NULL;
    temp=tempo;
}
void top(){
    cout<<temp->data<<endl;
}