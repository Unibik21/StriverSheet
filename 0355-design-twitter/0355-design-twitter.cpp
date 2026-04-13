class Twitter {
public:
    int time;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,set<int>>followers;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto &i:followers[userId]){
            vector<pair<int,int>>t = tweets[i];
            for(auto &j:t) pq.push(j);
        }
        vector<pair<int,int>>t = tweets[userId];
        for(auto &j:t) pq.push(j);

        vector<int>ans;
        int k =0;
        while(!pq.empty() && k<10){
            ans.push_back(pq.top().second);
            pq.pop();
            k++;
        }

        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */