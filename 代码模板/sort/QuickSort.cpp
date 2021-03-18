// leetcode-912. Sort an Array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std:random_device rd;
        std::mt19937 g(rd());
        std::shuffle(nums.begin(), nums.end(), g);
        
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    int partition(vector<int>& nums, int l, int r){
        int i = l + 1, j = r;
        int v = nums[l];
        while(true){
            while(i <= j && nums[i] < v) ++i;
            while(j >= i && nums[j] > v) --j;
            if(i >= j) break;
            swap(nums[i], nums[j]);
            ++i, --j;
        }
        swap(nums[l], nums[j]);
        return j;
    }
    
    void QuickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = partition(nums, l, r);
        QuickSort(nums, l, mid - 1);
        QuickSort(nums, mid + 1, r);
    }
};