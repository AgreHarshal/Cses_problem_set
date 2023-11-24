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
    vector<int> a(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> d[i];
    }
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    int curr = 0, max = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (a[i] < d[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        if (curr > max)
        {
            max = curr;
        }
    }
    cout << max << endl;
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