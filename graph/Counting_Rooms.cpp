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
void dfs(int v_x, int v_y, int p_x, int p_y, vector<vector<char>> &arr, int m, int n, vector<vector<bool>> &vis)
{
    vis[v_x][v_y] = true;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int new_x = v_x + dx[i];
        int new_y = v_y + dy[i];

        if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && arr[new_x][new_y] == '.' && vis[new_x][new_y] == false)
        {

            dfs(new_x, new_y, v_x, v_y, arr, m, n, vis);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && vis[i][j] == false)
            {

                dfs(i, j, -1, -1, arr, m, n, vis);
                count++;
            }
        }
    }
    cout << count << endl;
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
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}