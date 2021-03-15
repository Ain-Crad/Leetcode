// leetcode-228. Summary Ranges
// 用如下while的方式可以自动处理边界问题

// solution1-- recommand
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
            
        vector<string> ans;
        int l = 0, r = 0;
        while(l < n){
            while(r + 1 < n && nums[r] + 1 == nums[r + 1]) ++r;
            if(r == l) ans.push_back(to_string(nums[r]));
            else ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            ++r;
            l = r;
        }
        return ans;
    }
};

// solution2
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        
        vector<string> ans;
        int i = 0;
        while(i < n){
            int l = i, r = i;
            while(i + 1 < n && nums[i] + 1 == nums[i + 1]) ++i, ++r;
            if(r == l) ans.push_back(to_string(nums[r]));
            else ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            ++i;
        }
        return ans;
    }
};

// leetcode-443. String Compression
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, pos = 0;
        while(i < n){
            int l = i, r = i;
            while(i + 1 < n && chars[i] == chars[i + 1]) ++i, ++r;
            chars[pos++] = chars[l];
            if(r > l){
                int cnt = r - l + 1, pow = 1;
                while(cnt / (pow * 10)) pow *= 10;
                while(pow){
                    chars[pos++] = '0' + cnt / pow;
                    cnt %= pow;
                    pow /= 10;
                }
            }
            ++i;
        }
        return pos;
    }
};