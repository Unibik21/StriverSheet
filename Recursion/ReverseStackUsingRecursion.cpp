#include<iostream>
#include<stack>
using namespace std;

void insertinreversedSt(stack<int>&st,int temp){
    if(st.size()==0){
        st.push(temp);
        return;
    }
    int val =st.top();
    st.pop();
    insertinreversedSt(st,temp);
    st.push(val);
    return;
}

void reverseSt(stack<int>&st){
    if(st.size()==0)return;
    int temp= st.top();
    st.pop();
    reverseSt(st);
    insertinreversedSt(st,temp);
    return;
}

int main(){
    stack<int>st;
    st.push(5);
    st.push(7);
    st.push(2);
    st.push(8);
    st.push(9);
    st.push(1);

    reverseSt(st);
}