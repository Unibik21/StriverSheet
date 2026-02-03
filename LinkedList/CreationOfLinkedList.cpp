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

int main(){

    vector<int>arr = {1,2,3,4,5};
    Node* n = new Node(arr[0]);

    cout<<n<<endl;
    cout<<n->data<<endl;

}
