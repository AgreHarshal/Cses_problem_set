#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    if (n <= 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        vector<int> res;
        int i = 1;
        for (i = 1; i < n / 2; i++)
        {
            res.push_back(i);
            res.push_back(n - i + 1);
        }
        if (n % 2)
        {
            res.push_back(i);
            res.push_back(n - i + 1);
            res.insert(res.begin(), n / 2 + 1);
        }
        else
        {
            res.push_back(i);
            i++;
            res.insert(res.begin(), i);
        }
        for (auto j : res)
        {
            cout << j << " ";
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