/*Implement a problem of activity selection problem
with K persons.
Statement: Given two arrays S[] and E[] of size N denoting starting
and closing time of the shops and an integer value K denoting the
number of people, the task is to find out the maximum number of
shops they can visit in total if they visit each shop optimally based
on the following conditions:
 A shop can be visited by only one person
 A person cannot visit another shop if its timing collide with it
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
Output: 3
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold shop timings
struct Shop {
    int s, e;
};

// Comparator function to sort shops based on their eing time
bool compare(Shop a, Shop b) {
    return a.e < b.e;
}

// Function to find the maximum number of shops that can be visited by K persons
int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int N = S.size();
    vector<Shop> shops(N);

    // Store the s and e times in the Shop structure
    for (int i = 0; i < N; ++i) {
        shops[i] = {S[i], E[i]};
    }

    // Sort the shops based on their e times
    sort(shops.begin(), shops.end(), compare);

    vector<int> persons(K, 0);
    int cnt = 0;

    // Assign shops to persons optimally
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (persons[j] <= shops[i].s) {
                persons[j] = shops[i].e;
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

int main() {
    vector<int> S1 = {1, 8, 3, 3, 3};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S1, E1, K1) << endl;

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S2, E2, K2) << endl;

    return 0;
}
