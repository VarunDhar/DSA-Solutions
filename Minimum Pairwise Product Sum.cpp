#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include<utility>
#include<unordered_set>

using namespace std;

int dpfun(vector<int> &arr1, vector<int> &arr2, int pos1, int pos2, vector<vector<int>> &dp)
{
    if (pos1 >= arr1.size() or pos2 >= arr2.size())
        return 0;
    if (dp[pos1][pos2] != -1)
        return dp[pos1][pos2];
    int prod1 = 0, prod2 = 0, prod3 = 0;
    prod1 = dpfun(arr1, arr2, pos1 + 1, pos2 + 1, dp) + arr1[pos1] * arr2[pos2];
    prod2 = dpfun(arr1, arr2, pos1 + 1, pos2, dp);
    prod3 = dpfun(arr1, arr2, pos1, pos2 + 1, dp);
    return dp[pos1][pos2] = max({ prod1,prod2,prod3 });
} 

int main()
{
    vector<int> arr1 = { -1 ,2, 1 };
    vector<int> arr2 = { -100, 3, 10, -9 };
    vector<vector<int>> dp(arr1.size() + 5, vector<int>(arr2.size() + 5, -1));

    cout << dpfun(arr1,arr2,0,0,dp) << endl;
    return 0;
}
