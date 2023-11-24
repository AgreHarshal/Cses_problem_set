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
int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2)
    {
        return (x * (power(x, n - 1) % mod)) % mod;
    }
    else
    {
        return power(x * x, n / 2) % mod;
    }
}
void solve()
{
    int n;
    cin >> n;
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res * 2) % mod;
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