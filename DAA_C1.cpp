/*Implement Coin Change problem.
Statement Given an integer array of coins[ ] of
size N representing different types of currency and an
integer sum, The task is to find the number of ways to
make sum by using different combinations
from coins[].
Note: Assume that you have an infinite supply of each
type of coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5
    */
#include<iostream>
using namespace std;

int trails(int x){
    int cnt = 0;
    while (x>=5){
        x = x/5;
        cnt = cnt + x;  
    }
    return cnt;
}

int leastTrail(int n){
    int low = 0;
    int high = 6*n;

    if (n==1){
        return 5;
    }

    while (low<high)
    {
        int mid = (low + high) >> 1;
        cout<<low<<' '<<high<<' '<<mid<<" "<<trails(mid)<<endl;
        if (trails(mid)< n){
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    cout<< leastTrail(n);
    return 0;
}
