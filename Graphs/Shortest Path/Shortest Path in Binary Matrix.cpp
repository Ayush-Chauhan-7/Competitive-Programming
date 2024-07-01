    // https://leetcode.com/problems/shortest-path-in-binary-matrix/
    
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

    vector<int> dr = {0,-1,0,1,1,-1,1,-1};
    vector<int> dc = {1,0,-1,0,1,-1,-1,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])
            return -1;
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,-1));
        dist[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr>=0 && rr<n && cc>=0 && cc<n && dist[rr][cc]==-1 && grid[rr][cc]==0)
                {
                    dist[rr][cc] = dist[r][c] + 1;
                    q.push({rr,cc});
                }
            }
        }
        return dist[n-1][n-1];
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