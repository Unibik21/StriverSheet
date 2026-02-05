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

bool SearchForElement(Node* head,int val){
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}