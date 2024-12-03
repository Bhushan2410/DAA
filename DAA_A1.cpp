/*Implement a problem of number of zeroes.
Statement: Given an array of 1s and 0s which has all
1s first followed by all 0s? Find the number of 0s.
Count the number of zeroes in the given array.
Input: arr[] = {1, 1, 1, 1, 0, 0} Output: 2
Input: arr[] = {1, 0, 0, 0, 0} Output: 4*/
#include <bits/stdc++.h>
using namespace std;

int index_of_first_zero(int arr[], int n) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is the first 0
        if (arr[mid] == 0 && (mid == 0 || arr[mid - 1] == 1)) {
            return mid;
        }
        // If the middle element is 1, search in the right half
        else if (arr[mid] == 1) {
            low = mid + 1;
        }
        // If the middle element is 0, search in the left half
        else {
            high = mid - 1;
        }
    }
    
    // If no zero is found
    return -1;
}

int main() {
    int arr[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = index_of_first_zero(arr, n);
    
    if (pos == -1) {
        cout << "Count of zero is 0" << endl;
    }
    else {
        cout << "Count of zero is " << n - pos << endl;
    }
    
    return 0;
}
