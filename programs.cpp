#include<iostream>
using namespace std;

void Merge( int arr[],int low, int mid, int high){
    int i = low;
    int j = mid +1;
    int k = 0;
    int temp[100];
   //comparing the elements of array
    while(i>=mid && j<=high){
       if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
       }
       else{
        temp[k]=arr[j];
        j++;
       }
       k++;
    }
    //coping reamaining elements of left side
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
   //coping remaining elements of right side
   while(j<=high){
    temp[k]=arr[j];
    j++;
    k++;
   }
   //copy elements back to original array
   for(i=low,k=0;  i<=high ;i++,k++){
    arr[i]=temp[k];
   }
}
void merge_sort(int arr[], int low , int high){
if(low<high){
    int mid = (low+high)/2;
    merge_sort(arr,low,high);   //sorting left side
    merge_sort(arr,mid+1,high);  //sorting right side
    Merge(arr,low,mid,high);  //merging both sorted halves
}
}
int main(){
    int arr[]={23,54,11,90,88,73,2};
    int n =7;
    merge_sort(arr, 0, n-1);
    cout<< "sorted array:"<<"";
for(int i=0 ;i<n ;i++){
    cout << arr[i]<<"";
}
}
