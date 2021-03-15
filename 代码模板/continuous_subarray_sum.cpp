// 对于求是否存在区间满足区间元素之和可以被 K 整除的问题
// 可以边求prefix sum 边通过unordered_map记录前缀和的余数
// 余数相等的两个端点之前的区间即满足要求

//leetcode-523. Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(k != 0) sum %= k;
            if(mp.count(sum)){
                if(i - mp[sum] > 1) return true;
            }else{
                mp[sum] = i;
            }
        }
        return false;
    }
};

//leetcode-974. Subarray Sums Divisible by K
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int sum = 0, ans = 0;
        for(int i = 0; i < A.size(); ++i){
            sum = (sum + A[i]) % K;
            if(sum < 0) sum += K;
            if(mp.count(sum)){
                ans += mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};

// 变种
// leetcode-1590. Make Sum Divisible by P
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0, mod = 0, ans = nums.size();
        for(int &x : nums) sum = (sum + x) % p;
        mod = sum, sum = 0;
        if(mod == 0) return 0;
        
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        for(int i = 0; i < nums.size(); ++i){
            sum = (sum + nums[i]) % p;
            int comp = (sum - mod + p) % p;
            if(mp.count(comp)) ans = min(ans, i - mp[comp]);
            mp[sum] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};