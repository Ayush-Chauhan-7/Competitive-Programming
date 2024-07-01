    // https://leetcode.com/problems/rotting-oranges/
    
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

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({{i,j},0});
            }
        }
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};
        int ans = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            ans = max(ans,time);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr>=0 && cc>=0 && rr<n && cc<m && grid[rr][cc]==1)
                {
                    grid[rr][cc] = 2;
                    q.push({{rr,cc},time+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans=-1;
            }
        }
        return ans;
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