// 剑指 Offer 20. 表示数值的字符串

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), p = 0;
        while(p < n && isspace(s[p])) ++p;
        while(s.size() && isspace(s.back())) s.pop_back(), --n;
        
        bool num_seen = false, dot_seen = false, exp_seen = false;
        for(int i = p; i < n; ++i){
            if(isdigit(s[i])){
                num_seen = true;
            }else if(s[i] == '.'){
                // '.' 之前不能出现 '.' or 'e'
                if(dot_seen || exp_seen) return false;
                dot_seen = true;
            }else if(s[i] == 'e' || s[i] == 'E'){
                // 'e' 之前不能出现 'e'，必须出现数字
                if(!num_seen || exp_seen) return false;
                exp_seen = true;
                num_seen = false;
            }else if(s[i] == '+' || s[i] == '-'){
                // '+' 和 '-'只能出现在开头位置或 'e'之后的第一个位置
                if(i != p && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            }else{
                return false;
            }
        }
        return num_seen;
    }
};