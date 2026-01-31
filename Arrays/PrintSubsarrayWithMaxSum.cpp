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

    int sum = 0;
    int maxi = INT_MIN;


    int start =0;
    int ansStart =-1;
    int ansEnd = -1;

    for(int i=0;i<n;i++){
        if(sum==0){
            start =i;
        }
        sum+=arr[i];
        
        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }

        if(sum<0){
            sum=0;
        }
    }
    for(int i =ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    


}