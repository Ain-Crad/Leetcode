#include <vector>
#include <iostream>

using namespace std;

int get_second_min(vector<int>& arr){
    int n = arr.size();
    int min_idx = arr[0] < arr[1] ? 0 : 1;
    int sec_min_idx = 1 - min_idx;

    for(int i = 2; i < n; ++i){
        if(arr[i] < arr[min_idx]){
            sec_min_idx = min_idx;
            min_idx = i;
        }else if(arr[i] < arr[sec_min_idx]){
            sec_min_idx = i;
        }
    }
    return arr[sec_min_idx];
}

int main(){
    vector<int> arr{10, 1, 3, 4, -2, 9, 2};
    cout << get_second_min(arr) << endl;
    return 0;
}