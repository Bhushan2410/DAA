/*Implement a problem of smallest number with at
least n trailing zeroes in factorial.
Statement: Given a number n. The task is to find the
smallest number whose factorial contains at least n
trailing zeroes.
Input : n = 1 Output : 5
Input : n = 6 Output : 25
*/
#include <iostream>
using namespace std;

// Function to cnt the number of trailing zeroes in the factorial of num
int cntTrailingZeroes(int num) {
    int cnt = 0;
    while(num >= 5) {
        num /= 5;
        cnt += num;
    }
    return cnt;
}

// Function to find the smallest number whose factorial contains at least n trailing zeroes
int get_min_fact(int n) {
    if (n == 0) return 0; // Special case, 0! = 1, which has no trailing zero

    int low = 0;
    int high = 5 * n;  // Upper bound heuristic

    while (low < high) {
        int mid = (low + high) / 2;
        if (cntTrailingZeroes(mid) < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeroes required: ";
    cin >> n;

    int result = get_min_fact(n);
    cout << "The smallest number whose factorial has at least " << n << " trailing zeroes is: " << result << endl;

    return 0;
}
