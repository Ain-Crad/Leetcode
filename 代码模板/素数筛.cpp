// leetcode-204. Count Primes

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        int ans = 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i < n; ++i){
            if(isPrime[i]){
                ans++;
                for(int j = 2 * i; j < n; j += i) isPrime[j] = false;
            }
        }
        return ans;
    }
};