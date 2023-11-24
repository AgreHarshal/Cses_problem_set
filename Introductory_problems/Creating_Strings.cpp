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
void rec(set<string> &res, vector<bool> &vis, string s, string temp)
{
    int n = s.size();
    if (temp.size() == n)
    {
        res.insert(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            temp += s[i];
            rec(res, vis, s, temp);
            vis[i] = false;
            temp.pop_back();
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    set<string> res;
    vector<bool> vis(n + 1, false);
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            temp += s[i];
            rec(res, vis, s, temp);
            temp.pop_back();
            vis[i] = false;
        }
    }
    int tr = res.size();
    cout << tr << endl;
    for (auto i : res)
    {
        cout << i << endl;
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