/*Implement a problem of minimum work to be done
per day to finish given tasks within D days problem.
Statement: Given an array task[] of size N denoting
amount of work to be done for each task, the problem
is to find the minimum amount of work to be done on
each day so that all the tasks can be completed in at
most D days. Note: On one day work can be done for
only one task.
Input: task[] = [3, 4, 7, 15], D = 10
Output: 4
Input: task[] = [30, 20, 22, 4, 21], D = 6
Output: 22
*/
#include <bits/stdc++.h>
using namespace std;

// Function to check if
// all the task can be
// completed by 'per_day'
// number of task per day
bool check(int per_day,
		vector<int> task, int d)
{

	// Variable to store days required
	// to done all tasks
	int cur_day = 0;
	for (int index = 0; index < task.size();
		index++) {

		int day_req
			= ceil((double)(task[index])
				/ (double)(per_day));

		cur_day += day_req;

		// If more days required
		// than 'd' days so incheck

		if (cur_day > d) {
			return false;
		}
	}

	// check if days are less
	// than or equal to 'd'
	return cur_day <= d;
}

// Function to find minimum
// task done each day
int min_task(vector<int> task, int d)
{

	int low = 0;
	int high = 0;

	for (int index = 0;
		index < task.size();
		index++) {
		high = max(high, task[index]);
	}

	// Variable to store answer
	int per_day_task = 0;

	while (low <= high) {

		int mid = low
				+ (high - low) / 2;

		// If 'mid' number of task per day
		// is check so store as answer and
		// more to first half
		if (check(mid, task, d)) {
			per_day_task = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	// Print answer
	return per_day_task;
}

// Driver Code
int main()
{
	// Input taken
	vector<int> task{ 3, 4, 7, 15 };
	int D = 10;

	cout << min_task(task, D) << endl;

	return 0;
}
