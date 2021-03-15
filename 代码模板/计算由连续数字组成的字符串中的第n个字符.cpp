// leetcode-400. Nth Digit

// solution1--recommand
class Solution {
public:
    int findNthDigit(int n) {
        if(n == 0) return 0;

        // step 1. calculate how many digits the number has.
        long base = 9, digits_len = 1;
        while(n - base * digits_len > 0){
            n -= base * digits_len;
            base *= 10;
            digits_len++;
        }

        // step 2. calculate what the number is.
        int num = pow(10, digits_len - 1) + (n - 1) / digits_len;

        // step 3. find out which digit in the number is we wanted.
        int idx = (n - 1) % digits_len;

        return to_string(num)[idx] - '0';
    }
};

// solution2
// 首先通过二分找到包含第n个字符的数字，然后再计算第n个字符
class Solution {
public:
    int findNthDigit(int n) {
        long nth = static_cast<long>(n) + 1;

        int l = 0, r = INT_MAX;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(digitsNum(mid) < nth) l = mid + 1;
            else r = mid - 1;
        }

        long num = digitsNum(l);

        vector<int> digits;
        while(l){
            digits.push_back(l % 10);
            l /= 10;
        }

        return digits[num - nth];
    }

private:
    // 注意900000000后要加L表示long类型
    vector<long> rec{0, 10, 90 * 2, 900 * 3, 9000 * 4, 90000 * 5, 900000 * 6, 9000000 * 7, 90000000 * 8, 900000000L * 9};
    long digitsNum(int x){
        if(x < 10) return x + 1;

        vector<int> digits;
        while(x){
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());

        int len = digits.size();

        long res = 0;
        for(int i = 0; i < len; ++i) res += rec[i];

        res += (digits[0] - 1) * pow(10, len - 1) * len;
        for(int i = 1; i < len - 1; ++i){
            if(digits[i] > 0) res += digits[i] * pow(10, len - 1 - i) * len;
        }
        res += (digits[len - 1] + 1) * 1 * len;

        return res;

    }
};