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
int help(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }

    if (index < 0)
    {
        return 0;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    int res = 0;
    int nottake = help(index - 1, target, arr, dp);
    if (target - arr[index] >= 0)
    {
        int take = help(index, target - arr[index], arr, dp);
        res = (take + nottake) % mod;
    }
    else
    {
        res = nottake;
    }
    return dp[index][target] = res;
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

    vector<int> dp1(x + 1, 0);
    dp1[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                dp1[i] = (dp1[i] + dp1[i - arr[j]]) % mod;
            }
        }
    }
    cout << dp1[x] << endl;
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
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}