#include<iostream>
#include<vector>
using namespace std;


int LIS(int arr[],int n){
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int l=0;
            int h=temp.size()-1;
            int idx =-1;
            while(l<=h){
                int m = l+(h-l)/2;

                if(temp[m]<arr[i]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            temp[l]=arr[i];
        }
    }
    return temp.size();
}

int main(){

}