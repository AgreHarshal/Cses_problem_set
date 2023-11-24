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
    int res = n / 2 + (n % 2);
    if (res % 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        if (n % 2 == 0)
        {
            int num1 = n / 2 + n % 2;
            cout << num1 << endl;
            int i = 1;
            while (i <= num1 / 2)
            {
                cout << i << " ";
                if (i != (n - i + 1))
                {
                    cout << n - i + 1 << " ";
                }
                i++;
            }

            cout << endl;
            int num2 = n / 2;
            i = num1 / 2 + 1;
            cout << num2 << endl;
            while (i <= n / 2 + n % 2)
            {
                cout << i << " ";
                if (i != (n - i + 1))
                {
                    cout << n - i + 1 << " ";
                }
                i++;
            }
        }
        else
        {
            vector<int> a;
            vector<int> b;
            int num1 = n / 2 + n % 2;
            int i = 1;
            while (i <= num1 / 2)
            {
                a.push_back(i);
                if (i != (n - i + 1))
                {
                    a.push_back(n - i + 1);
                }
                i++;
            }
            int num2 = n / 2;
            i = num1 / 2 + 1;
            while (i <= n / 2 + n % 2)
            {
                b.push_back(i);
                if (i != (n - i + 1))
                {
                    b.push_back(n - i + 1);
                }
                i++;
            }
            int a_size = a.size();
            int b_size = b.size();
            int temp = a[a_size - 1];
            a[a_size - 1] = b[b_size - 1];
            b[b_size - 1] = temp;
            cout << a_size << endl;
            for (auto p : a)
            {
                cout << p << " ";
            }
            cout << endl;
            cout << b_size << endl;
            for (auto p : b)
            {
                cout << p << " ";
            }
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