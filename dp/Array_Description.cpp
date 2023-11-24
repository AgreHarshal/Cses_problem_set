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
int help(int index, int last, vector<int> &arr, int m, vector<vector<int>> &dp)
{
    if (last > m || last <= 0)
    {
        return 0;
    }

    if (index < 0)
    {
        return 1;
    }
    if (dp[index][last] != -1)
    {
        return dp[index][last];
    }
    int dx[] = {-1, 0, 1};
    int res = 0;
    if (arr[index] == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (last + dx[i] > 0)
            {
                int check = help(index - 1, last + dx[i], arr, m, dp);
                res = (res + check) % mod;
                res %= mod;
            }
        }
    }
    else
    {
        if (abs(arr[index] - last) > 1)
        {
            return 0;
        }
        else
        {
            int check = help(index - 1, arr[index], arr, m, dp);
            res = (res + check) % mod;
            res %= mod;
        }
    }
    return dp[index][last] = res;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int res = 0;
    if (arr[n - 1] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            int check = help(n - 2, i, arr, m, dp);
            if (check != -1)
            {
                res += check;
                res %= mod;
            }
        }
    }
    else
    {
        res = help(n - 2, arr[n - 1], arr, m, dp);
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
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}