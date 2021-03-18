#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

void sort(vector<int> &vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        int minIndex = i;
        for(int j = i + 1; j < n; ++j){
            if(vec[j] < vec[minIndex]) minIndex = j;
        }
        int tmp = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = tmp;
    }
}