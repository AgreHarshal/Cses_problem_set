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
    int x, y;
    cin >> y >> x;
    if (x > y)
    {
        if (x % 2)
        {
            int sn = ((x) * (2 + (x - 1) * 2)) / 2;
            sn -= (y - 1);
            cout << sn << endl;
        }
        else
        {

            int sn = ((x - 1) * (2 + (x - 2) * 2)) / 2;
            sn++;
            sn += (y - 1);
            cout << sn << endl;
        }
    }
    else
    {
        if (y % 2)
        {
            int sn = ((y - 1) * (2 + (y - 2) * 2)) / 2;
            sn++;
            sn += (x - 1);
            cout << sn << endl;
        }
        else
        {

            int sn = ((y) * (2 + (y - 1) * 2)) / 2;
            sn -= (x - 1);
            cout << sn << endl;
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    precal();
    // solve();
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << 'CASE' << t << ':' ;
        solve();
    }
    return 0;
}