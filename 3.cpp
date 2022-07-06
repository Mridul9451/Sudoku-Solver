#include <bits/stdc++.h>
using namespace std;

int a[9][9];

bool check(int x, int y, int z)
{
    for (int i = 0; i < 9; i++)
    {
        if (a[x][i] == z)
        {
            return false;
        }
        if (a[i][y] == z)
        {
            return false;
        }
    }
    int l = (x / 3) * 3;
    int r = (y / 3) * 3;
    for (int i = l; i < l + 3; i++)
    {
        for (int j = r; j < r + 3; j++)
        {
            if (a[i][j] == z)
            {
                return false;
            }
        }
    }
    return true;
}

void rec(int x, int y)
{
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << a[i][j];
            }
            cout << "\n";
        }
        return;
    }
    if (a[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(x, y, i))
            {
                a[x][y] = i;
                if (y == 8)
                {
                    rec(x + 1, 0);
                }
                else
                {
                    rec(x, y + 1);
                }
            }
            a[x][y] = 0;
        }
    }
    else
    {
        if (y == 8)
        {
            rec(x + 1, 0);
        }
        else
        {
            rec(x, y + 1);
        }
    }
}

void solve()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char ch;
            cin >> ch;
            if (ch != '.')
            {
                a[i][j] = ch - '0';
            }
        }
    }
    rec(0, 0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}