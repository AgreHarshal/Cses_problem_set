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
int rec(int i1, int i2, string s1, string s2)
{
    if (i1 < 0 || i2 < 0)
    {
        return 0;
    }
    int res = 0;
    if (s1[i1] == s2[i2])
    {
        res = rec(i1 - 1, i2 - 1, s1, s2);
    }
    else
    {

        res = min(res, rec(i1 - 1, i2, s1, s2));
        res = min(res, rec(i1, i2 - 1, s1, s2));
        res = min(res, rec(i1 - 1, i2 - 1, s1, s2));
        res++;
    }
    return res;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    int res = rec(n1 - 1, n2 - 1, s1, s2);
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