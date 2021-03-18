int quickPower(int x, int mod){
    long long res = 1, cur = 2;
    while(x){
        if(x & 1) res = (res * cur) % mod;
        x >>= 1;
        cur = (cur * cur) % mod;
    }
    return res;
}