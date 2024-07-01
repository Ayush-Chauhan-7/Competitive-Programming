    // https://leetcode.com/problems/critical-connections-in-a-network/
    
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

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), bridges;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n), in(n), low(n);
        int timer=1;
        auto dfs = [&](int u, int p, auto&& dfs) -> void
        {
            vis[u] = 1;
            in[u] = low[u] = timer;
            timer++;
            for(auto v: adj[u])
            {
                if(v==p)
                    continue;
                if(!vis[v])
                    dfs(v,u,dfs);
                low[u] = min(low[u],low[v]);
                if(low[v]>in[u])
                    bridges.push_back({u,v});
            }
        };
        dfs(0,-1,dfs);
        return bridges;
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