#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d,Node* n){
        data =d;
        next = n;
    }
    Node(int d){
        data=d;
        next = NULL;
    }
};

Node* reverseLL(Node* head){
    if(head==NULL || head-> next==NULL)return head;

    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;

}

Node* Add1(Node* head){
    Node* newHead = reverseLL(head);
    Node* temp = newHead;
    int carry =1;
    while(temp){
        int sum = carry+temp->data;
        temp->data = sum%10;
        carry =sum/10;

        if(temp->next==NULL && carry!=0){
            temp->next = new Node(carry);
            break;
        }

        temp=temp->next;
    }

    Node* OHead = reverseLL(newHead);
    return OHead;
}

int main(){
    return 0;
}