#include<iostream>
#include<vector>

using namespace std;

void CntAllSubWithSumk(int sum,int i,int k,vector<int>&ans,vector<int>nums){
    if(i==nums.size()){
        if(sum==k){
            for(int l=0;l<ans.size();l++){
                cout<<ans[l]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ans.push_back(nums[i]);
    CntAllSubWithSumk(sum+nums[i],i+1,k,ans,nums);
    ans.pop_back();
    CntAllSubWithSumk(sum,i+1,k,ans,nums);
}

int main(){
    
    
}