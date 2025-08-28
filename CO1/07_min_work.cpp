/*
Implement a problem of minimum work to be done per day to finish given tasks within D days.

Statement:
Given an array task[] of size N denoting amount of work to be done for each task, 
the problem is to find the minimum amount of work to be done on each day so that all the tasks 
can be completed in at most D days.

Note: On one day, work can be done for only one task.

Sample Input:
Enter number of tasks: 3
Enter work for each task: 2
4
7
Enter number of days: 2

Sample Output:
Minimum work per day required = 7
*/

#include <iostream>
using namespace std;

bool canDistribute(double tasks[], int n, int d, double maxWork)
{
    int daysUsed = 1; // start with 1st day
    double currentLoad = 0;

    for (int i = 0; i < n; i++)
    {
        if (tasks[i] > maxWork)
            return false; // single task > limit (not possible)

        if (currentLoad + tasks[i] <= maxWork)
        {
            currentLoad += tasks[i]; // put in same day
        }
        else
        {
            daysUsed++; // start new day
            currentLoad = tasks[i];
            if (daysUsed > d)
                return false; // too many days
        }
    }
    return true;
}

int main()
{
    int n, d;
    cout << "Enter number of tasks: ";
    cin >> n;

    double tasks[100];
    cout << "Enter work for each task: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i];
    }

    cout << "Enter number of days: ";
    cin >> d;

    // total sum and max element
    double totalWork = 0, maxTask = 0;
    for (int i = 0; i < n; i++)
    {
        totalWork += tasks[i];
        if (tasks[i] > maxTask)
            maxTask = tasks[i];
    }

    // binary search
    double low = maxTask, high = totalWork, ans = totalWork;
    while (low <= high)
    {
        double mid = (low + high) / 2;
        if (canDistribute(tasks, n, d, mid))
        {
            ans = mid; // possible, try smaller
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Minimum work per day required = " << ans << endl;
    return 0;
}