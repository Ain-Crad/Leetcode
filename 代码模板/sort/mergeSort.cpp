#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

// template 1
typedef vector<int>::iterator iterator;
void mergeSort(iterator l, iterator r){
    if(r - l <= 1) return;
    iterator mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid, r);
    inplace_merge(l, mid, r);
}


// template 2 -- recommend
vector<int> aux;
void mergesort(vector<int>& arr, int l, int r, int& ans){
    if(l >= r) return;

    int mid = l + (r - l) / 2;
    mergesort(arr, l, mid, ans);
    mergesort(arr, mid + 1, r, ans);

    for(int k = l; k <= r; ++k) aux[k] = arr[k];

    int i = l, j = mid + 1;
    for(int k = l; k <= r; ++k){
        if(i > mid) arr[k] = aux[j++];
        else if(j > r) arr[k] = aux[i++];
        else if(aux[i] > aux[j]) arr[k] = aux[j++];
        else arr[k] = aux[i++];
    }
}