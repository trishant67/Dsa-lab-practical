#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    // Comparing elements of both halves
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left side
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right side
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy elements back to original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Sorting left half
        merge_sort(arr, low, mid);

        // Sorting right half
        merge_sort(arr, mid + 1, high);

        // Merging both sorted halves
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {23, 54, 11, 90, 88, 73, 2};
    int n = 7;

    merge_sort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}