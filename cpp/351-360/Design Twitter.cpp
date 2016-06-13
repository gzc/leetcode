class Twitter {
    
    map<int, int> tweetTimeMap;
    int time;
    map<int, vector<int>> userTweetMap;
    map<int, vector<int>> followMap;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(userTweetMap.count(userId) == 0) {
            vector<int> myvec;
            userTweetMap[userId] = myvec;
        }
        userTweetMap[userId].push_back(tweetId);
        tweetTimeMap[tweetId] = ++time;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        vector<int> follows = followMap[userId];
        follows.push_back(userId);
        
        vector<int> idxs(follows.size(), 0);
        
        for(int i = 0;i < follows.size(); i++) {
            idxs[i] = userTweetMap[follows[i]].size() - 1;
        }
        
        for(int k = 0; k < 10; k++) {
            int tempidx;
            int tweetId;
            int latestTime(-1);
            
            for(int i = 0;i < idxs.size();i++) {
                if(idxs[i] < 0) continue;
                int tweetid = userTweetMap[follows[i]][idxs[i]];
                int thisTime = tweetTimeMap[tweetid];
                
                if(thisTime > latestTime) {
                    tempidx = i;
                    tweetId = tweetid;
                    latestTime = thisTime;
                }
            }
            
            if(latestTime < 0) break;
            
            idxs[tempidx]--;
            
            res.push_back(tweetId);
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(followMap.count(followerId) == 0) {
            vector<int> myvec;
            followMap[followerId] = myvec;
        }
        
        vector<int> myvec = followMap[followerId];
        for(int i = 0;i < myvec.size();i++)
            if(myvec[i] == followeeId)
                return;
        
        followMap[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        int idx(-1);
        vector<int> myvec = followMap[followerId];
        for(int i = 0;i < myvec.size();i++) {
            if(myvec[i] == followeeId) {
                idx = i;
                break;
            }
        }
        if(idx < 0) return;
        myvec.erase(myvec.begin() + idx);
        followMap[followerId] = myvec;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
