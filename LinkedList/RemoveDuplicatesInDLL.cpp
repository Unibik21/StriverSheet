//sorted DLL

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d,Node* n,Node*p){
        data =d;
        next = n;
        prev = p;
    }
    Node(int d){
        data=d;
        next = NULL;
        prev =NULL;
    }
};

Node* RemoveDuplicates(Node* head){

    if(head==NULL) return head;

    Node* temp = head;

    while(temp->next && temp){
        if(temp->data==temp->next->data){
            if(temp->next->next){
                temp->next->next->prev = temp;
                temp->next = temp->next->next;
            }
            else{
                temp->next = NULL;
                break;
            }
        }
        else{
            temp=temp->next;
        }
    }

    return head;
}