// leetcode-剑指 Offer 51. 数组中的逆序对

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n <= 1) return 0;

        vector<int> aux(n, 0);
        mergeSort(nums, 0, n - 1, aux, ans);

        return ans;
    }

private:
    void mergeSort(vector<int>& nums, int l, int r, vector<int>& aux, int& ans){
        if(l == r) return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid, aux, ans);
        mergeSort(nums, mid + 1, r, aux, ans);
        
        for(int k = l; k <= r; ++k) aux[k] = nums[k];

        int i = l, j = mid + 1;
        for(int k = l; k <= r; ++k){
            if(i > mid) nums[k] = aux[j++];
            else if(j > r) nums[k] = aux[i++], ans += r - mid;
            else if(aux[i] > aux[j]) nums[k] = aux[j++];
            else nums[k] = aux[i++], ans += j - mid - 1;
        }
    }
};