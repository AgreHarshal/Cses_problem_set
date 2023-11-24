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
    vector<int> arr(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {

        if (mp.count(arr[i]) != 0)
        {
            if (mp[arr[i]].first >= 1)
            {
                last = max(last, mp[arr[i]].second + 1);
                mp[arr[i]].second = i;
            }
            else
            {
                mp[arr[i]].first++;
                mp[arr[i]].second = i;
            }
        }
        else
        {
            mp[arr[i]].first++;
            mp[arr[i]].second = i;
        }
        res = max(res, i - last + 1);
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