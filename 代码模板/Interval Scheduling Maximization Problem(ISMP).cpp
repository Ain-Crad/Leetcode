// Interval Scheduling Maximization Problem (ISMP) -- find the maximum size of non-overlapping ranges given a set of ranges.
// We just need to sort the ranges in ascending order of the ending index, and then greedily pick the non-overlapping ranges which end first.

// leetcode-1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> v;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            if(mp.count(sum - target)) v.push_back({i, mp[sum - target] + 1});
            mp[sum] = i;
        }
        sort(v.begin(), v.end());
        int ans = 0, last = -1;
        for(auto &p : v){
            if(p[1] <= last) continue;
            ++ans;
            last = p[0];
        }
        return ans;
        
    }
};

// 变种问题，求在区间不冲突的情况下需要的最小的房间数
// 对开始时间进行升序排序， 用priority_queue维护即将要结束的区间终点
// leetcode-253. Meeting Rooms II
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        priority_queue<int, vector<int>, greater<int>> que;
        int ans = 0;
        for(int i = 0; i < intervals.size(); ++i){
            if(que.size() && intervals[i][0] >= que.top()) que.pop();
            que.push(intervals[i][1]);
            ans = max(ans, static_cast<int>(que.size()));
        } 
        return ans;
    }
};