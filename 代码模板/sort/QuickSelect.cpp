class Solution {
public:
    vector<int> smallestK(vector<int>& nums, int k) {
        if(k == 0) return {};

        random_device rd;
        mt19937 g(rd());
        shuffle(nums.begin(), nums.end(), g);

        QuickSelect(nums, 0, nums.size() - 1, k);
        
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(nums[i]);
        }
        return ans;
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

    void QuickSelect(vector<int>& nums, int l, int r, int k){
        if(l >= r) return;

        int mid = partition(nums, l, r);
        int len = mid - l + 1;
        if(len == k){
            return;
        }else if(len > k){
            QuickSelect(nums, l, mid - 1, k);
        }else{
            QuickSelect(nums, mid + 1, r, k - len);
        }
    }
};