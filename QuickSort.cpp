#include <iostream>
using namespace std;

int Partition(int arr[], int s , int e){
int pivot = arr[s];

int count = 0;
for(int i = s+1 ; i < e ; i++){
    if(arr[i] <= pivot){
        count++;
    }
}
//place pivot at correct position
int pivotIndex = s + count;
swap(arr[s],arr[pivotIndex]);

//solving for left and right side 
int i = s;
int j = e;
while(i < pivotIndex && j > pivotIndex){
    while(arr[i] < pivot){
        i++;
}
    while(arr[j] > pivot){
        j--;
    } 
    if(i < pivotIndex && j > pivotIndex){
        swap(arr[i],arr[j]);
    }
    return pivotIndex;
}
}
void quickSort(int arr[] , int s , int e){
//base case
if(s>=e){
    return;
}
//partition
int p = Partition(arr, s , e);
//sort left part
quickSort(arr, s ,p-1);
//sort right side
quickSort(arr, p+1 ,e);
}

int main(){
    int arr[10]= {23,12,66,4,10,2,26,77,99,100};
    int n = 10;
    quickSort(arr, 0 , n-1);
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}