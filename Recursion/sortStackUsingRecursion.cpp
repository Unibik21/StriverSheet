#include<iostream>
#include<stack>
using namespace std;

void insertStack(stack<int>&st,int temp){
    if(!st.empty() && st.top()<=temp){
        st.push(temp);
        return;
    }
    if(st.empty()){
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insertStack(st,temp);
    st.push(val);

    return;
}

void sortStack(stack<int>&st){
    if(st.size()==1) return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertStack(st,temp);
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

    sortStack(st);
}
