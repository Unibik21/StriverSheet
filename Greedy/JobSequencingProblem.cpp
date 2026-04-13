#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct Job {
   int id; 
   int dead; 
   int profit; 
};

pair < int, int > JobScheduling(vector<Job>job, int n) {
    sort(job.begin(),job.end(),[](Job &a,Job &b){
        return a.profit>b.profit;
    });
    int maxD = -1;
    for(int i=0;i<n;i++){
        if(job[i].dead>maxD)maxD=job[i].dead;
    }

    vector<int>day(maxD+1,-1);
    int maxProfit =0;
    int jobcnt =0;
    for( Job &i:job){
        int d = i.dead;
        int ID = i.id;
        while(d){
            if(day[d]==-1){
                day[d]=ID;
                maxProfit+=i.profit;
                jobcnt++;
                break;
            }
            d--;
        }
    }
    return {jobcnt,maxProfit};
}

int main(){

}