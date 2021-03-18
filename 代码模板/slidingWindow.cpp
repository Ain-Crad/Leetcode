// leetcode-992. Subarrays with K Different Integers
// 模板 solution1
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> cnt;
        int n = A.size(), prefix = 0, len = 0, ans = 0;
        
        for(int i = 0, j = 0; i < n; ++i){
            if(cnt[A[i]]++ == 0) ++len;
            if(len > K){
                --cnt[A[j]];
                --len;
                ++j;
                prefix = 0;
            }
            
            while(j < i && cnt[A[j]] > 1) --cnt[A[j]], ++j, ++prefix;
            
            if(len == K) ans += prefix + 1; 
        }
        
        return ans;
    }
};

// solution2
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> cnt;
        int n = A.size(), prefix = 0, len = 0, ans = 0;
        
        int j = 0, i = 0;
        while(i < n){
            if(cnt[A[i]]++ == 0) ++len;
            if(len > K){
                --cnt[A[j]];
                --len;
                ++j;
                prefix = 0;
            }
            
            while(j < i && cnt[A[j]] > 1) --cnt[A[j]], ++j, ++prefix;
            
            if(len == K) ans += prefix + 1; 

            ++i;
        }
        
        return ans;
    }
};


// leetcode-76. Minimum Window Substring
// 注意如何通过cnt来判断窗口是否包含全部t中字符

class Solution {
public:
    string minWindow(string s, string t) {
        int minLeft = -1, minRight = -1, len = INT_MAX;
        int cnt = t.size();
        unordered_map<char, int> mp;
        for(auto &c : t) mp[c]++;
        
        int l = 0, r = 0;
        while(r < s.size()){
            char c = s[r];
            if(mp.find(c) != mp.end()){
                mp[c]--;
                if(mp[c] >= 0) cnt--;
            }
            while(cnt <= 0 && l <= r){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    minLeft = l;
                    minRight = r; 
                }
                c = s[l];
                if(mp.find(c) != mp.end()){
                    mp[c]++;
                    if(mp[c] > 0) cnt++;
                }
                ++l;
            }
            ++r;
        }
        return minLeft == -1 ? "" : s.substr(minLeft, len);
    }
};

// leetcode-438. Find All Anagrams in a String
// 区间长度固定
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m > n) return {};
        
        vector<int> ans;
        unordered_map<char, int> mp;
        for(char &c : p) mp[c]++;
        int cnt = p.size();
        int l = 0, r = 0;
        for(r = 0; r < m; ++r){
            mp[s[r]]--;
            if(mp[s[r]] >= 0) --cnt;
        }
        if(cnt == 0) ans.push_back(0);
        
        while(r < s.size()){
            if(mp.find(s[l]) != mp.end()){
                mp[s[l]]++;
                if(mp[s[l]] > 0) ++cnt;
            }
            ++l;
            
            if(mp.find(s[r]) != mp.end()){
                mp[s[r]]--;
                if(mp[s[r]] >= 0) --cnt;
            }
            ++r;
            
            if(cnt == 0) ans.push_back(l);
        }
        return ans;
    }
};