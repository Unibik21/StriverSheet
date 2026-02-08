#include<iostream>
#include<vector>

using namespace std;

bool CntAllSubWithSumk(int sum,int i,int k,vector<int>&ans,vector<int>nums){
    if(i==nums.size()){
        if(sum==k){
           return true; 
        }
        return false;
    }
    ans.push_back(nums[i]);
    if(CntAllSubWithSumk(sum+nums[i],i+1,k,ans,nums)) return true;
    ans.pop_back();
    if(CntAllSubWithSumk(sum,i+1,k,ans,nums)) return true;
    
    return false;
}

int main(){
    
    
}