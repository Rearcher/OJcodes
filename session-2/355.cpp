// 355. Design Twitter
#include "leetcode.hpp"
using namespace std;

class Twitter {
public:
    Twitter() {
        timestamp = 0;
        tweets = {};
        follows = {};
    }

    void postTweet(int userId, int tweetId) {
        if (tweets.count(userId)) tweets[userId].push_back(make_pair(timestamp, tweetId));
        else tweets[userId] = {make_pair(timestamp, tweetId)};

        timestamp += 1;
    }

    vector<int> getNewsFeed(int userId) {
        set<int> followees = follows[userId];
        followees.insert(userId);

        auto cmp = [&](pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);

        for (int followee : followees) {
            if (!tweets.count(followee)) continue;
            vector<pair<int, int>> tweet = tweets[followee];

            for (pair<int, int> t : tweet)
                maxHeap.push(t);
        }

        vector<int> result;
        for (int i = 0; i < 10 && maxHeap.size(); ++i) {
            int id = maxHeap.top().second;
            result.push_back(id);
            maxHeap.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (follows.count(followerId)) follows[followerId].insert(followeeId);
        else follows[followerId] = {followeeId};
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId) && follows[followerId].count(followeeId))
            follows[followerId].erase(followeeId);
    }

private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, set<int>> follows;
};

int main() {
    Twitter tw;
    vector<int> news;

    tw.postTweet(1, 5);
    news = tw.getNewsFeed(1);

    tw.follow(1, 2);
    tw.postTweet(2, 6);
    news = tw.getNewsFeed(1);

    tw.unfollow(1, 2);
    news = tw.getNewsFeed(1);

    for (auto i : news) cout << i << " ";
    cout << "\n";
}