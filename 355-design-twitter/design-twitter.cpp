class Twitter {
public:
    vector<pair<int, int>> feed; // uid, tid
    map<int, unordered_set<int>> user_following_list;
    Twitter() {
        
    }
    
    void postTweet(int uid, int tid) {
        feed.push_back({uid, tid});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = feed.size() - 1;
        int cnt = 0;
        int j = 0;
        vector<int> latest_feed;
        while (cnt < 10 && n >= 0) {
            if (userId == feed[n].first || user_following_list[userId].count(feed[n].first)) {
                latest_feed.push_back(feed[n].second);
                cnt++;
            }
            n--;
        }
        return latest_feed;
    }
    
    void follow(int followerId, int followeeId) {
        user_following_list[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (user_following_list[followerId].count(followeeId))  user_following_list[followerId].erase(followeeId);
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