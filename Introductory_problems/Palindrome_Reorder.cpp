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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(26, 0);
    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2)
        {
            odd++;
        }
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        string res = "";
        int odd = 1e9;
        for (int i = 0; i < 26; i++)
        {
            int freq = arr[i];
            if (freq % 2 == 0)
            {
                for (int j = 0; j < freq / 2; j++)
                {
                    res += (char)(i + 'A');
                }
            }
            else
            {
                odd = i;
            }
        }
        if (odd != 1e9)
        {
            for (int j = 0; j < arr[odd] / 2; j++)
            {
                res += (char)(odd + 'A');
            }
            string temp = res;
            reverse(temp.begin(), temp.end());
            res += (char)(odd + 'A');
            res += temp;
            cout << res << endl;
        }
        else
        {
            string temp = res;
            reverse(temp.begin(), temp.end());
            res += temp;
            cout << res << endl;
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