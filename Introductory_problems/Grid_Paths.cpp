#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void precal()
{
}
bool vis[7][7];
int total_paths = 0;
void paths_count(int r, int c, int &paths)
{
    vis[r][c] = true;
    if (r == 6 && vis[r][c] == true && r - 1 >= 0 && vis[r - 1][c] == true && c + 1 < 7 && vis[r][c + 1] == false && c - 1 >= 0 && vis[r][c - 1] == false)
    {
        vis[r][c] = false;
        return;
    }
    if (r == 0 && vis[r][c] == true && r + 1 < 7 && vis[r + 1][c] == true && c + 1 < 7 && vis[r][c + 1] == false && c - 1 >= 0 && vis[r][c - 1] == false)
    {
        vis[r][c] = false;
        return;
    }
    if (c == 0 && vis[r][c] == true && c + 1 < 7 && vis[r][c + 1] == true && r + 1 < 7 && vis[r + 1][c] == false && c - 1 >= 0 && vis[r][c - 1] == false)
    {
        vis[r][c] = false;
        return;
    }
    if (c == 6 && vis[r][c] == true && c - 1 < 7 && vis[r][c - 1] == true && r + 1 < 7 && vis[r + 1][c] == false && r - 1 >= 0 && vis[r - 1][c] == false)
    {
        vis[r][c] = false;
        return;
    }

    if (paths == 48 && r == 6 && c == 0)
    {
        total_paths++;
        cout << total_paths << endl;
        return;
    }
    else if (paths >= 48)
    {
        return;
    }
    if (r + 1 < 7 && vis[r + 1][c] == false)
    {
        paths++;
        paths_count(r + 1, c, paths);
        paths--;
    }
    if (c - 1 >= 0 && vis[r][c - 1] == false)
    {
        paths++;
        paths_count(r, c - 1, paths);
        paths--;
    }
    if (r - 1 >= 0 && vis[r - 1][c] == false)
    {
        paths++;
        paths_count(r - 1, c, paths);
        paths--;
    }
    if (c + 1 < 7 && vis[r][c + 1] == false)
    {
        paths++;
        paths_count(r, c + 1, paths);
        paths--;
    }
    vis[r][c] = false;
}
void solve()
{
    int paths = 1;
    paths_count(0, 0, paths);
    cout << total_paths << endl;
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