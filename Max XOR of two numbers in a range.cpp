#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

int dpfun(int curr,int last, const int &B ,vector<vector<int>> &dp)
{
    if (curr > B)
        return -1;
    if (dp[curr][last] != -1) return dp[curr][last];

    else
    {
        int a=0, b=0;
        a = max(dpfun(curr + 1, curr, B,dp), dpfun(curr + 1, last,B, dp));
	    if(last!=0)
	    {
            b = curr ^ last;
            cout << curr << " " << last<<" - "<<b << endl;
	    }
        return dp[curr][last ] = max(a, b);
    }
}
int main()
{
    int A = 12, B = 16;

    vector<vector<int>> dp(B + 1, vector<int>(B + 1, -1));
    cout<< dpfun(A, 0, B, dp);
    return 0;
}
