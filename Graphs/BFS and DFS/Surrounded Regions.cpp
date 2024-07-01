    // https://leetcode.com/problems/surrounded-regions/
    
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


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        auto dfs = [&](int i, int j, auto&& dfs) -> void {
            if(i<0 || i==n || j<0 || j==m || vis[i][j] || board[i][j]=='X')
                return;
            vis[i][j] = true;
            dfs(i+1,j,dfs);
            dfs(i,j+1,dfs);
            dfs(i-1,j,dfs);
            dfs(i,j-1,dfs);
        };
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i,0,dfs);
            if(board[i][m-1]=='O' && !vis[i][m-1])
                dfs(i,m-1,dfs);
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && !vis[0][i])
                dfs(0,i,dfs);
            if(board[n-1][i]=='O' && !vis[n-1][i])
                dfs(n-1,i,dfs);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                    board[i][j] = 'X';
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
        return 0;
    }