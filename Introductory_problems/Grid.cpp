#include <bits/stdc++.h>
using namespace std;

bool vis[7][7];
int total_paths = 0;

void paths_count(int r, int c, int paths)
{
    if (r < 0 || r >= 7 || c < 0 || c >= 7 || vis[r][c] || paths > 48)
    {
        return;
    }

    vis[r][c] = true;

    if (r == 6 && c == 0 && paths == 48)
    {
        total_paths++;
        cout << total_paths << endl;
        vis[r][c] = false; // Backtrack
        return;
    }

    paths_count(r + 1, c, paths + 1);
    paths_count(r - 1, c, paths + 1);
    paths_count(r, c + 1, paths + 1);
    paths_count(r, c - 1, paths + 1);

    vis[r][c] = false; // Backtrack
}

void solve()
{
    paths_count(0, 0, 1);
    cout << total_paths << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
