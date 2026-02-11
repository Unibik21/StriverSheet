#include<iostream>
using namespace std;


int arr[100];
int ptr1 = -1;
int ptr2 =0;
int maxCapacity = 100;

void push(int n){
    if(ptr1==100){
        cout<<"Stack OverFlow";
    }
    ptr1++;
    arr[ptr1]=n;

    for(int i=ptr2;i<ptr1+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void pop(){
    if(ptr1<ptr2){
        cout<<"Stack Already Empty"<<endl;
        return;
    }
    ptr2++;
    for(int i=ptr2;i<=ptr1;i++){
        cout<<arr[i]<<" ";
    }
}

void front(){
    if(ptr1<ptr2){
        cout<<"Stack Empty"<<endl;
        return;
    }
    cout<<arr[ptr2]<<endl;
}

int main(){
    
}
