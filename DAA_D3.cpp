/*Implement program to print all subsets of a given
Set or Array
Statement Given a set of positive integers, find all its
subsets.
Input: array = {1, 2, 3}
Output: // this space denotes null element.
 {1} {1 2} {1 2 3} {1 3} {2}
{2 3} {3}
Input: 1 2
Output: 1 2 1 2
  */
#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int>& A, vector<vector<int> >& res,
                vector<int>& subset, int index)
{
    res.push_back(subset);

    for (int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);

        calcSubset(A, res, subset, i + 1);

        // Exclude the current element from the subset
        // (backtracking)
        subset.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

int main()
{
    vector<int> array = { 1, 2, 3 };
    vector<vector<int> > res = subsets(array);

    // Print the generated subsets
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
