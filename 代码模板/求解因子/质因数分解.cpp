#include <iostream>
#include <vector>

// 若是对大量数据进行质因数分析，只需要针对数据里最大的值进行一次prime数组的构造

std::vector<int> GetFactors(int v){
    std::vector<int> prime(v + 1, 0);
    prime[1] = 1;
    for(int i = 2; i < v + 1; ++i){
        if(prime[i] == 0){
            for(int j = i; j < v + 1; j += i){
                prime[j] = i;
            }
        }
    }

    std::vector<int> factors;
    while(v > 1){
        int factor = prime[v];
        factors.push_back(factor);
        v /= factor;
    }
    return factors;
}

int main(){
    std::vector<int> ans = GetFactors(12);
    for(int x : ans) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}