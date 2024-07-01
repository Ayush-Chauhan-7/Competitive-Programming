    // https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
    
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


    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<pair<int,int>> config;
        auto dfs = [&](int i, int j, int r0, int c0, auto&& dfs) -> void
        {
            vis[i][j] = true;
            config.push_back({i-r0,j-c0});
            if(i && grid[i-1][j] && !vis[i-1][j])
                dfs(i-1,j,r0,c0,dfs);
            if(j && grid[i][j-1] && !vis[i][j-1])
                dfs(i,j-1,r0,c0,dfs);
            if(i<n-1 && grid[i+1][j] && !vis[i+1][j])
                dfs(i+1,j,r0,c0,dfs);
            if(j<m-1 && grid[i][j+1] && !vis[i][j+1])
                dfs(i,j+1,r0,c0,dfs);
        };
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    config.clear();
                    dfs(i,j,i,j,dfs);
                    st.insert(config);
                }
            }
        }
        return st.size();
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        return 0;
    }