#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

void sort(vector<int> &vec){
    int n = vec.size();
    for(int i = 1; i < n; ++i){
        for(int j = i; j > 0; --j){
            if(vec[j] < vec[j - 1]){
                int tmp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = tmp;
            }
        }
    }
}