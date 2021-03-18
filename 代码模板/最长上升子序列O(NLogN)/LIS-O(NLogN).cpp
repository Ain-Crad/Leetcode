// Longest Increasing Sequence的O(NLogN)解法
// leetcode-300. Longest Increasing Subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> stacks;
        for(int i = 0; i < n; ++i){
            if(stacks.empty() || nums[i] > stacks.back()){
                stacks.push_back(nums[i]);
            }else{
                int idx = BinarySearch(stacks, nums[i]);
                stacks[idx] = nums[i];
            }
        }
        return stacks.size();
    }
    
private:
    int BinarySearch(vector<int>& stacks, int v){
        int l = 0, r = stacks.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(stacks[mid] < v) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};