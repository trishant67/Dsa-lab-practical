#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    int arr[6] = {2, 5, 23, 6, 1, 99};
    int n = 6;

    SelectionSort(arr, n);

    cout << "the sorted array :" << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}