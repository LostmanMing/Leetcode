#include<vector>
#include<iostream>
using namespace std;

int partation(vector<int>& arr, int l,int r){
    int i = l, j = r;
    int val = arr[l];
    while(i < j){
        while(i < j && arr[j] > val) j--;
        if(i < j){
            arr[i] = arr[j];
            i++;
        }
        while(i < j && arr[i] <= val) i++;
        if(i < j){
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = val;
    return i;
}

void quickSort(vector<int>& arr, int l,int r){
    if(l < r){
        int pos = partation(arr,l,r);
        quickSort(arr,0,pos-1);
        quickSort(arr,pos+1,r);
    }
}



int main(){
    vector<int> arr{4,2,3,1,5};
    quickSort(arr,0,4);
    for(auto & a : arr){
        std::cout << a << " " << std::endl;
    }
    return 0;
}