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
    string a, b;
    cin >> a >> b;
    int n = a.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1' || b[i] == '1')
        {
            res.push_back(i);
        }
    }
    int q = res.size();
    for (int i = 0; i < q; i++)
    {
        if (a[res[i]] == '1' && b[res[i]] == '1')
        {
            if (a[res[i] - 1] == '0' && b[res[i] - 1] == '0')
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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