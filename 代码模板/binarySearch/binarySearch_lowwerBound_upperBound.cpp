// template--左闭右开区间 和 左闭右闭区间两种模板

// 左闭右开区间[)
int bsearch(int *A, int x, int y, int v){
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(A[m] == v) return m;
        else if(A[m] > v) y = m;
        else x = m + 1;
    }

    return -1;
}

int lower_bound(int *A, int x, int y, int v){
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(A[m] >= v) y = m;
        else x = m + 1;
    }

    return x;
}

int upper_bound(int *A, int x, int y, int v){
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(A[m] > v) y = m;
        else x = m + 1; 
    }

    return x;
}

// 左闭右闭区间[]

int bsearch(int *A, int x, int y, int v){
    int m;
    while(x <= y){
        m = x + (y - x) / 2;
        if(A[m] == v) return m;
        else if(A[m] > v) y = m - 1;
        else x = m + 1;
    }

    return -1;
}

int lower_bound(int *A, int x, int y, int v){
    int m;
    while(x <= y){
        m = x + (y - x) / 2;
        if(A[m] >= v) y = m - 1;
        else x = m + 1;
    }

    return x;
}

int upper_bound(int *A, int x, int y, int v){
    int m;
    while(x <= y){
        m = x + (y - x) / 2;
        if(A[m] > v) y = m - 1;
        else x = m + 1; 
    }

    return x;
}


// leetcode-34. Find First and Last Position of Element in Sorted Array
// warning: mid = (l + r) / 2 might overflow, so it is good to write mid = l + (r - l) / 2

// solution1--recommend
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        int l = 0, r = n;
        int lowwer, upper;
        
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        lowwer = l;
        if(lowwer >= n || nums[l] != target) return {-1, -1};
        
        l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        upper = l - 1;
        return {lowwer, upper};
    }
};


// solution2
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        if(l >= n || nums[l] != target) return {-1, -1};
        
        int start = l, end = l;
        l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        end = l - 1;
        return {start, end};
    }
};

// leetcode-1552. Magnetic Force Between Two Balls
// 求满足要求的最大值，即upperbound - 1
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1, r = position[n - 1] - position[0] + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(position, mid, m)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l - 1;
    }
private:
    bool check(vector<int> &position, int dis, int m){
        int idx = 0;
        m--;
        for(int i = 1; i < position.size(); ++i){
            if(position[i] - position[idx] >= dis){
                --m;
                idx = i;
            }
            if(m == 0) return true;
        }
        return false;
    }
};

// leetcode-410-Split Array Largest Sum
// 求满足要求的最小值，即lowwerbound
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int max_val = 0;
        long long sum = 1;
        for(auto &x : nums){
            max_val = max(max_val, x);
            sum += x;
        }
        long long l = max_val, r = sum;
        while(l < r){
            long long mid = l + (r - l) / 2;
            if(!check(nums, mid, m)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    
private:
    bool check(vector<int> &nums, long long mid, int m){
        long long sum = 0;
        int i = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(sum > mid){
                cnt++;
                --i;
                sum = 0;
                if(cnt > m) return false;
            }else if(i == nums.size() - 1){
                cnt++;
            }
        }
        return cnt <= m;
    }
};