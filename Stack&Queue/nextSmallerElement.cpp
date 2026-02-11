#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>NextSmallerElement(vector<int>arr){
    stack<int>st;
    for(int i=arr.size()-1;i>=0;i--){
        if(st.empty()){
            st.push(arr[i]);
            arr[i]=-1;
        }
        else{
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            if(st.empty()){
                st.push(arr[i]);
                arr[i]=-1;
            }
            else{
                int t = arr[i];
                arr[i]=st.top();
                st.push(t);
            }

            
        }
    }
    return arr;
}

int main(){

}