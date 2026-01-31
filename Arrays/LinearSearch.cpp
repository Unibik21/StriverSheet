//TC = N
//SC = 1



#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int num;
    cin>>num;

    bool b= false;
    for(int i=0;i<n;i++){
        if(num == arr[i]){
            cout<<i<<endl;
            b=true;
            break;
        }
    }
    if(!b){
        cout<<-1<<endl;
    }

}