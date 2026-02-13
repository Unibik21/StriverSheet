    #include<iostream>
    #include<vector>
    using namespace std;

    bool solve(int i,int target,vector<int>&arr){
        if(target==0){
            return true;
        }
        if(i==0 && target==arr[i])return true;
        if(i==0 && target!=arr[i])return false;
        bool notTake = solve(i-1,target,arr);
        bool Take =false;
        if(target>=arr[i]) Take = solve(i-1,target-arr[i],arr);

        return (notTake || Take);
    }


    int main(){

    }