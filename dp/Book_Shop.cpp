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
int help(int index, vector<int> &pages, vector<int> &price, int target, vector<vector<int>> &dp)
{
    if (index < 0 || target <= 0)
    {
        return 0;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    int nottake = help(index - 1, pages, price, target, dp);
    int take = INT_MIN;
    if (price[index] <= target)
    {
        take = pages[index] + help(index - 1, pages, price, target - price[index], dp);
    }
    return dp[index][target] = max(take, nottake);
}
void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (j >= price[i - 1])
            {
                curr[j] = max(prev[j], pages[i - 1] + prev[j - price[i - 1]]);
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    cout << prev[target] << endl;
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