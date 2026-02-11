#include<iostream>
using namespace std;


int arr[100];
int ptr = -1;
int maxCapacity = 100;

void push(int n){
    if(ptr==100){
        cout<<"Stack OverFlow";
    }
    ptr++;
    arr[ptr]=n;

    for(int i=0;i<ptr+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void pop(){
    if(ptr==-1){
        cout<<"Stack Already Empty"<<endl;
        return;
    }
    ptr--;
    for(int i=0;i<ptr;i++){
        cout<<arr[i]<<" ";
    }
}

void top(){
    if(ptr==-1){
        cout<<"Stack Empty"<<endl;
        return;
    }
    cout<<arr[ptr]<<endl;
}

int main(){
    push(10);
    top();
    pop();
    pop();
    push(2);
    push(3);
    push(5);
    top();
    pop();
    top();
}
