//TC = n
//SC = 4

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

    int maxi = arr[0];
    int maxi2 = INT_MIN;
    int mini = arr[0];
    int mini2 = INT_MAX;

    for(int i=1;i<n;i++){
        if(arr[i]>=maxi){
            maxi2 = maxi;
            maxi = arr[i];
        }
        if(arr[i]<maxi && arr[i]>maxi2){
            maxi2 = arr[i];
        }
        if(arr[i]<= mini){
            mini2 = mini;
            mini = arr[i];
        }
        if(arr[i]>mini && arr[i]<mini2){
            mini2 = arr[i];
        }
    }

    cout<<"2nd MAXIMUM = "<<maxi2<<endl;
    cout<<"2nd Minimum = "<<mini2<<endl;
}