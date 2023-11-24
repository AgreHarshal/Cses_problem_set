#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void precal()
{
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int help(int target, vector<int> &arr, int n, vector<int> &dp)
{
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int mini = INT_MAX;
    if (target == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            mini = min(mini, 1 + help(target - arr[i], arr, n, dp));
        }
    }
    return dp[target] = mini;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(x + 1, -1);
    int res = help(x, arr, n, dp);
    if (res == INT_MAX)
    {
        res = -1;
    }
    cout << res << endl;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    precal();
    solve();
    //   int tc;
    //   cin >> tc;
    //   for (int t = 1; t <= tc; t++)
    //   {
    //       // cout << 'CASE' << t << ':' ;
    //       solve();
    //   }
    return 0;
}