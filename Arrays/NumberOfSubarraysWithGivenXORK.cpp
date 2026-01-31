#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int Txor = 0;
    unordered_map<int,int>freq;
    int cnt =0;
    freq[0]=1;

    for(int i=0;i<n;i++){
        Txor = Txor^arr[i];

        if(freq.find(Txor^k)!=freq.end()){
            cnt+=freq[Txor^k];
        }
        freq[Txor]++;
    }

    cout<<cnt<<endl;

}