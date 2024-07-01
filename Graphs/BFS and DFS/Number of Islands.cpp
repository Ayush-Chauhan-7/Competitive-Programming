    // https://leetcode.com/problems/number-of-islands/
    
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

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        auto dfs = [&](int i, int j, auto&& dfs) -> void {
            vis[i][j] = true;
            if(i && grid[i-1][j]=='1' && !vis[i-1][j])
                dfs(i-1,j,dfs);
            if(j && grid[i][j-1]=='1' && !vis[i][j-1])
                dfs(i,j-1,dfs);
            if(i<n-1 && grid[i+1][j]=='1' && !vis[i+1][j])
                dfs(i+1,j,dfs);
            if(j<m-1 && grid[i][j+1]=='1' && !vis[i][j+1])
                dfs(i,j+1,dfs);
        };
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    c++;
                    dfs(i,j,dfs);
                }
            }
        }
        return c;
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