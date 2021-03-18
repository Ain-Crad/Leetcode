// leetcode-31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;
        
        // 找到最先打破降序排列的元素
        int p = n - 1;
        while(p > 0 && nums[p] <= nums[p - 1]) --p;
        
        if(p == 0){
            // 表示整个序列已经是降序序列，直接反转
            reverse(nums.begin(), nums.end());
        }else{
            // 找到 p 在其右的降序序列的严格上确界
            int i = n - 1;
            while(i >= p && nums[i] <= nums[p - 1]) --i;
            // 交换元素
            swap(nums[p - 1], nums[i]);
            // 降序序列部分反转
            reverse(nums.begin() + p, nums.end());
        }
    }
};