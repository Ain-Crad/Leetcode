class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 1 && num1[0] == '0') return "0";
        if(num2.size() == 1 && num2[0] == '0') return "0";
        int n = num1.size(), m = num2.size();
        string ans(n + m, '0');
        for(int i = num1.size() - 1; i >= 0; --i){
            int carry = 0, digit = 0;
            for(int j = num2.size() - 1; j >= 0; --j){
                int val = (num1[i] - '0') * (num2[j] - '0') + carry;
                int index = num1.size() - 1 - i + num2.size() - 1 - j;
                val += ans[index] - '0';
                ans[index] = val % 10 + '0';
                carry = val / 10;
            }
            if(carry > 0){
                int head = num2.size() + num1.size() - 1 - i;
                ans[head] = carry + '0';
            }
        }
        for(int i = ans.size() - 1; i >= 0; ++i){
            if(ans[i] != '0') break;
            else ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};