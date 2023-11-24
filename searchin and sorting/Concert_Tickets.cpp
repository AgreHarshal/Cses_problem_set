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
    int n, m;
    cin >> n >> m;
    vector<int> price_ticket(n);
    vector<pair<int, int>> price(m);
    for (int i = 0; i < n; i++)
    {
        cin >> price_ticket[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price_ticket[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> price[i].first;
        price[i].second = i;
    }
    sort(price_ticket.begin(), price_ticket.end());
    sort(price.begin(), price.end());
    int i = 0, j = 0;
    vector<pair<int, int>> res;
    while (j < m && i < n)
    {
        if (price_ticket[i] <= price[j].first)
        {
            res.push_back({price[j].second, price[j].first - price_ticket[i]});
            j++;
            i++;
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