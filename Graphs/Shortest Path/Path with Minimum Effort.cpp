    // https://leetcode.com/problems/path-with-minimum-effort/
    
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

    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        priority_queue <pair<int,pair<int,int>>,vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        q.push({0,{0,0}});
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {-1,0,1,0};
        while(!q.empty())
        {
            auto x = q.top();
            q.pop();
            int dis = x.first;
            int r = x.second.first;
            int c = x.second.second;
            if(dis!=dist[r][c])
                continue;
            if(r==n-1 && c==m-1)
                return dis;
            for(int i=0;i<4;i++)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(rr<0 || rr==n || cc<0 || cc==m)
                    continue;
                int nd = max(dis, abs(grid[r][c]-grid[rr][cc]));
                if(nd<dist[rr][cc])
                {
                    dist[rr][cc] = nd;
                    q.push({nd,{rr,cc}});
                }
            }
        }
        return 0;
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