#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector<bool> prime(100, true);
void precal()
{
    for (int i = 2; i < 100; i++)
    {
        for (int j = i * i; j < 100; j += i)
        {

            prime[j] = false;
        }
    }
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
    string res = "";
    for (int k = 0; k < 8; k++)
    {
        int j = s[k] - '0';
        for (int i = j * 10; i < (j + 1) * 10; i++)
        {
            if (prime[i] == true && i % 10 != (i / 10) % 10)
            {

                cout << i << endl;
                return;
            }
        }
    }
    cout << "-1" << endl;
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