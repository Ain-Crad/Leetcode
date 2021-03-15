// leetcode-440. K-th Smallest in Lexicographical Order
// reference-https://www.youtube.com/watch?v=yMnR63e3KLo&feature=youtu.be&ab_channel=coderZ

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        while(k > 1){
            long gap = GetGap(cur, cur + 1, n);
            if(gap < k){
                k -= gap;
                cur = cur + 1;
            }else{
                k -= 1;
                cur = cur * 10;
            }
        }
        return cur;
    }
    
private:
    long GetGap(long a, long b, long n){
        long res = 0;
        while(a <= n){
            res += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return res;
    }
};