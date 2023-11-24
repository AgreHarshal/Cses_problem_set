#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void precal()
{
}
string mat[8];
int vis[8][8];
bool isvalid(int i, int j)
{
    bool possible = true;
    if (mat[i][j] == '*')
    {
        possible = false;
        return false;
    }
    int px = i, py = j;
    while (px >= 0)
    {
        if (vis[px][j] == 1)
        {
            return false;
        }
        px--;
    }
    px = i;
    while (px < 8)
    {
        if (vis[px][j] == 1)
        {
            return false;
        }
        px++;
    }
    while (py >= 0)
    {
        if (vis[i][py] == 1)
        {
            return false;
        }
        py--;
    }
    py = j;
    while (py < 8)
    {
        if (vis[i][py] == 1)
        {
            return false;
        }
        py++;
    }
    px = i, py = j;
    while (px >= 0 && py >= 0)
    {
        if (vis[px][py] == true)
        {
            return false;
        }
        px--;
        py--;
    }
    px = i, py = j;
    while (px <= 7 && py <= 7)
    {
        if (vis[px][py] == 1)
        {
            return false;
        }
        px++;
        py++;
    }
    px = i, py = j;
    while (px <= 7 && py >= 0)
    {
        if (vis[px][py] == 1)
        {
            return false;
        }
        px++;
        py--;
    }
    px = i, py = j;
    while (px >= 0 && py <= 7)
    {
        if (vis[px][py] == 1)
        {
            return false;
        }
        px--;
        py++;
    }
    return true;
}
int res = 0;
void rec(int col)
{

    if (col == 8)
    {
        res++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (isvalid(i, col))
        {
            vis[i][col] = 1;
            rec(col + 1);
            vis[i][col] = 0;
        }
    }
}
void solve()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> mat[i];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vis[i][j] = 0;
        }
    }
    rec(0);
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
    //   int tc;
    //   cin >> tc;
    //   for (int t = 1; t <= tc; t++)
    //   {
    //       // cout << 'CASE' << t << ':' ;
    //       solve();
    //   }
    return 0;
}