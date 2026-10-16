#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for (int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n-1 ; j++){
            if(arr[j]>arr[j+1]){
            swap (arr[j],arr[j+1]);
        }
    }
}
}
int main(){
    int arr[6]= {2,5,56,70,1,44};
    int n = 6;
    BubbleSort(arr,n);
    cout << "sorted array:"<< " ";
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
