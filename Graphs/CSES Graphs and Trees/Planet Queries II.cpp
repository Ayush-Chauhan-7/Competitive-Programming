    #include <bits/stdc++.h>
    typedef long long ll;
    #define fo(i, n) for(ll i=0;i<n;i++)
    #define vi vector<ll>
    #define vp vector< pair <ll,ll> >
    #define f first
    #define s second
    #define pb push_back
    #define endl '\n'

    using namespace std;


    const int N = 1e5 + 2;
    const int mod = 1e9 + 7;
    const long long int maxi = 1e15;
    
    vector<vector<int>> succ;
    vector<int> vis;
    vector<int> len;
    
    void dfs(int s) {
        if (vis[s]) return;
        vis[s] = 1;
        dfs(succ[0][s]);
        len[s] = len[succ[0][s]] + 1;
    }
    
    int lift(int x, int d) {
        if (d <= 0) {
            return x;
        }
        int i = 0;
        while (d > 0) {
            if (d & 1) {
                x = succ[i][x];
            }
            d >>= 1;
            i++;
        }
        return x;
    }

    void solve()
    {
        int n, q;
        cin >> n >> q;
        succ.assign(21, vector<int>(n + 1, 0));
        vis.assign(n + 1, 0);
        len.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> succ[0][i];
        }
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= n; j++) {
                succ[i][j] = succ[i - 1][succ[i - 1][j]];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            int ans = 0, m = len[x], mm = len[y];
            ans += len[x] - len[y];
            int h = x;
            for (int i = 0; i <= 20; ++i) if ((m - len[y]) & (1 << i)) h = succ[i][h];
            if (h == y && len[x] >= len[y]) cout << ans << endl;
            else {
                for (int i = 0; i <= 20; ++i) if (m & (1 << i)) x = succ[i][x];
                int g = x;
                if (len[x] > len[y]) {
                    for (int i = 0; i <= 20; ++i) {
                        if ((len[g] - mm) & (1 << i)) x = succ[i][x];
                    }
                }
                if (x == y) cout << m + len[g] - mm << endl;
                else cout << -1 << endl;
            }
        }
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }