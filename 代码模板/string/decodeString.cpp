// 一道string类型的典型题，有一些通用的需要注意的地方，例如isdigit的判断，一定要注意不一定只有一位digit !!!
// 所以要用while求出连续digits代表的整数

// leetcode-394. Decode String

class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return solve(s, idx);
    }
    
private:
    string solve(string &s, int &idx){
        string ans;
        while(idx < s.size() && s[idx] != ']'){
            if(isdigit(s[idx])){
                int k = 0;
                while(isdigit(s[idx])) k = k * 10 + s[idx++] - '0';
                ++idx;
                string t = solve(s, idx);
                ++idx;
                while(k--) ans += t;
            }else{
                ans.push_back(s[idx++]);
            }
        }
        return ans;
    }
};