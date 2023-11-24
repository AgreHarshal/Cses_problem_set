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
int final_length = INT_MAX;
string res = "";
int dfs(int v_x, int v_y, int p_x, int p_y, vector<vector<char>> &arr, int m, int n, vector<vector<int>> &vis)
{
    if (arr[v_x][v_y] == 'B')
    {
        return 0;
    }
    if (vis[v_x][v_y] != -1)
    {
        return vis[v_x][v_y];
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int mini = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        int new_x = v_x + dx[i];
        int new_y = v_y + dy[i];
        bool flag = true;
        if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && new_x != v_x && new_y != v_y && (arr[new_x][new_y] == '.' || arr[new_x][new_y] == 'B'))
        {
            flag = false;
            mini = min(mini, 1 + dfs(new_x, new_y, v_x, v_y, arr, m, n, vis));
            cout << new_x << " " << new_y << endl;
        }
        if (flag)
        {
            vis[v_x][v_y] = -1;
            return -1;
        }
    }
    if (mini = INT_MAX)
    {
        vis[v_x][v_y] = -1;
    }
    return vis[v_x][v_y];
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
    vector<vector<int>> vis(n, vector<int>(m, -1));
    string s = "";
    int final_x;
    int final_y;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 'A')
            {

                res = dfs(i, j, -1, -1, arr, m, n, vis);
                final_x = i;
                final_y = j;
                break;
            }
        }
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
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}