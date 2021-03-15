// 分割数组为连续子序列
// leetcode-659. Split Array into Consecutive Subsequences
// cnt记录元素x的个数，end记录以x为结尾的序列的个数
// 对于一个数x，优先考虑把它加入以x - 1为结尾的序列中，如果不满足才考虑以它为开头新创建一个序列

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, end;
        for(int x : nums) ++cnt[x];
        for(int x : nums){
            if(cnt[x] == 0) continue;

            --cnt[x];
            if(end[x - 1] > 0){
                --end[x - 1], ++end[x];
            }else if(cnt[x + 1] > 0 && cnt[x + 2] > 0){
                --cnt[x + 1], --cnt[x + 2], ++end[x + 2];
            }else{
                return false;
            }
        }
        return true;
    }
};