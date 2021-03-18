// leetcode-224. Basic Calculator
// leetcode-227. Basic Calculator II
// leetcode-772. Basic Calculator III

// s[start + 1] - '0' 用括号括起来(s[start + 1] - '0')可以防止溢出，因为 '0'-'9'对应的ASCII码为48-57， 如果前面的数接近INT_MAX就会溢出
class Solution {
public:
    int calculate(string s) {
        int n = s.size(), start = 0;
        return solve(s, start);
    }

private:
    bool isoperator(char c){
        if(c == '+' || c == '-' || c == '*' || c == '/') return true;
        else return false;
    }

    int solve(string& s, int& start){
        int n = s.size(), val = 0;
        char sign = '+';
        stack<int> vals;

        while(start < n){
            if(isdigit(s[start])){
                val = s[start] - '0';
                while(start + 1 < n && isdigit(s[start + 1])) val = val * 10 + (s[start + 1] - '0'), ++start;
            }else if(isoperator(s[start])){
                switch(sign){
                    case '+': vals.push(val); break;
                    case '-': vals.push(-val); break;
                    case '*': vals.top() *= val; break;
                    case '/': vals.top() /= val; break;
                }
                val = 0;
                sign = s[start];
            }else if(s[start] == '('){
                val = solve(s, ++start);
            }else if(s[start] == ')'){
                break;
            }

            ++start;
        }

        switch(sign){
            case '+': vals.push(val); break;
            case '-': vals.push(-val); break;
            case '*': vals.top() *= val; break;
            case '/': vals.top() /= val; break;
        }

        int ans = 0;
        while(vals.size()){
            ans += vals.top();
            vals.pop();
        }
        return ans;
    }
};