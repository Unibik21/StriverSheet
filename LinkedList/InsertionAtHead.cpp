#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

Node* InsertionAtFront(Node* head,int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

void PrintList(Node* head){

    while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
    }
}

int main(){

    Node* head = new Node(2);
    head->next = new Node(3);

    head = InsertionAtFront(head,1);
    PrintList(head);
}