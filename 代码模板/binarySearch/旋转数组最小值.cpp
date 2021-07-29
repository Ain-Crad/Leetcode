// leetcode-153
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 虽然 r 取得是nums.size() - 1 而不是 nums.size(), while循环条件仍然可以是 l < r, 
        // 因为对于这道题而言，结果一定存在于数组中，不像upper_bound一样有可能是数组外
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

// leetcode-154
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[r]) r = mid;
            else if(nums[mid] > nums[r]) l = mid + 1;
            else --r;
        }
        return nums[l];
    }
};