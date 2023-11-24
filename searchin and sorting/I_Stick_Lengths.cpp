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
int count(vector<int> &arr, int mid, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (abs(mid - arr[i]));
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int high = 0;
    int low = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        high = max(high, arr[i]);
    }
    int res = 0;
    int mid = low + (high - low) / 2;
    int md = count(arr, mid, n);
    int ans = 1e15;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        md = count(arr, mid, n);
        ans = min(md, ans);
        if (count(arr, mid + 1, n) < md)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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