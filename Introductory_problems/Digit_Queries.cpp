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
    vector<int> start_pos(20, 1);
    for (int i = 1; i < 19; i++)
    {
        start_pos[i] = start_pos[i - 1] * 10;
    }
    int ans = 0;
    int digits_until_now = 0;
    int current_digit = 0;
    int prev_digits = 0;
    for (int i = 1; i < 19; i++)
    {
        current_digit = prev_digits + (start_pos[i] - start_pos[i - 1]) * i;
        if (current_digit >= n)
        {
            ans = i;
            break;
        }
        prev_digits = current_digit;
    }
    int low = start_pos[ans - 1];
    int high = start_pos[ans] - 1;
    int final_ans = low;
    int ans_digit = 0;
    while (low <= high)
    {
        int mid = ((low + high) / 2);
        int digits = (mid - start_pos[ans - 1]) * ans + prev_digits + 1;
        if (digits <= n)
        {
            final_ans = mid;
            low = mid + 1;
            ans_digit = digits;
        }
        else
        {
            high = mid - 1;
        }
    }
    string res = to_string(final_ans);
    cout << res[n - ans_digit] << endl;
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