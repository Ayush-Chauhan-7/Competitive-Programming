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

    void solve()
    {
        ll n,m,ans=0;
        cin>>n>>m;
        string grid[n];
        fo(i,n)
            cin>>grid[i];
        auto dfs = [&grid, n, m](int i, int j, auto&& dfs) -> void {
            if(i<0 || i==n || j<0 || j==m || grid[i][j]=='#')
                return;
            grid[i][j] = '#';
            dfs(i+1,j,dfs);
            dfs(i,j+1,dfs);
            dfs(i-1,j,dfs);
            dfs(i,j-1,dfs);
        };
        fo(i,n)
        {
            fo(j,m)
            {
                if(grid[i][j]=='.')
                {
                    ans++;
                    dfs(i,j,dfs);
                }
            }
        }
        cout<<ans<<endl;
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