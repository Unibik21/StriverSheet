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

    int sum1 = 0;
    int sum2 = 0;

    for(int i=0;i<n;i++){
        sum1+=arr[i];
        sum2+= (arr[i]*arr[i]);
    }

    int Tsum1 = n*(n+1)/2;
    int Tsum2 = n*(n+1)*(2*n+1)/6;

    int diff = sum1-Tsum1;
    int diff2 = sum2-Tsum2;
    int add = diff2/diff ;

    int b = (diff + add)/2;
    int a  = b- diff;

    cout<<a<<" "<<b<<endl;
}