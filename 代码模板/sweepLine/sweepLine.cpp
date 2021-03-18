// leetcode-1109. Corporate Flight Bookings
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cnt(n, 0);
        for(auto &booking : bookings){
            cnt[booking[0] - 1] += booking[2];
            if(booking[1] < n) cnt[booking[1]] -= booking[2];
        }
        for(int i = 1; i < n; ++i){
            cnt[i] += cnt[i - 1];
        }
        return cnt;        
    }
};

// leetcode-1589. Maximum Sum Obtained of Any Permutation
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for(auto &p : requests){
            cnt[p[0]] += 1;
            if(p[1] + 1 < n) cnt[p[1] + 1] -= 1;
        }
        for(int i = 1; i < n; ++i){
            cnt[i] += cnt[i - 1];
        }
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        long sum = 0, mod = 1e9 + 7;
        for(int i = 0; i < n; ++i){
            sum += cnt[i] * nums[i];
            sum %= mod;
        }
        return sum;
    }
};