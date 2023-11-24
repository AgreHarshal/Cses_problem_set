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
void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 6; i++)
    {
        dp[i] = 0;
        int j = i;
        while (j >= 1)
        {
            dp[i] += dp[j];
            j--;
        }
        dp[i]++;
    }
    for (int i = 7; i <= n; i++)
    {
        dp[i] = 0;
        int j = i;
        while (j >= i - 6)
        {
            dp[i] = (dp[i] + dp[j]) % mod;
            j--;
        }
    }
    cout << dp[n] << endl;
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
