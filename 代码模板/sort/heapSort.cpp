#include <vector>

using namespace std;

void sink(vector<int>& arr, int k, int end){
    while(2 * k + 1 <= end){
        int j = 2 * k + 1;
        if(j + 1 <= end && arr[j] < arr[j + 1]) ++j;
        if(arr[k] >= arr[j]) break;
        swap(arr[k], arr[j]);
        k = j;
    }
}

void heapSort(vector<int>& arr){
    int end = arr.size() - 1;
    for(int k = (end - 1) / 2; k >= 0; --k){
        sink(arr, k, end);
    }
    while(end > 0){
        swap(arr[0], arr[end]);
        --end;
        sink(arr, 0, end);
    }
}