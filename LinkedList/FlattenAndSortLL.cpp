#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int d,Node* n,Node*c){
        data =d;
        next = n;
        child = c;
    }
    Node(int d){
        data=d;
        next = NULL;
        child =NULL;
    }
};

Node* merge2sortedLL(Node* left,Node* right){
    Node* sorted = new Node(-1);
    Node* temp = sorted;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            temp->next=left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    if(left){
        temp->next=left;
    }
    if(right){
        temp->next=right;
    }

    return sorted->next;
}

Node* sortLL(Node* head){

    if(head==NULL || head->next==NULL)return head;

    Node* fast = head->next;
    Node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* middle = slow->next;
    slow->next = NULL;

    Node* left = sortLL(head);
    Node* right = sortLL(middle);

    return merge2sortedLL(left,right);

}


Node* FlattenAndSortLL(Node* head){
    if(!head) return head;
    Node* temp = head;
    while(temp!=NULL){
        Node* n = temp->next;
        temp->next = NULL;
        while(temp->child){
            temp->next = temp->child;
            temp->child = NULL;
            temp=temp->next;
        }
        temp->next = n;
        temp = n;
    }

    Node* newhead =sortLL(head);

    return newhead;
}

int main(){
    return 0;
}