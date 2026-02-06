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

Node* deleteFromDll(Node* head,int k){

    if(head==NULL || (head->data=k && head->next==NULL))return nullptr;
    
    Node* temp = head;

    while(temp){
        if(temp->data==k){
            if(temp->prev==NULL){
                head = temp->next;
                temp = temp->next;
                temp->prev=NULL;
            }
            else{
                temp->prev->next = temp->next;
                if(temp->next){
                    temp->next->prev = temp->prev;
                }
                temp=temp->next;
            }
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}