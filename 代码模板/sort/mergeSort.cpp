#include<iostream>
#include<vector>

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


// template 2
vector<int> aux;

void merge(vector<int> &arr, int l, int mid, int r){
    for(int k = l; k < r; ++k){
        aux[k] = arr[k];
    }
    int i = l, j = mid;
    for(int k = l; k < r; ++k){
        if(i >= mid) arr[k] = aux[j++];
        else if(j >= r) arr[k] = aux[i++];
        else if(aux[i] > aux[j]) arr[k] = aux[j++];
        else arr[k] = aux[i++];
    }
}

void sort(vector<int> &arr, int l, int r){
    if(r - l <= 1) return;
    int mid = l + (r - l) / 2;
    sort(arr, l, mid);
    sort(arr, mid, r);
    merge(arr, l, mid, r);
}