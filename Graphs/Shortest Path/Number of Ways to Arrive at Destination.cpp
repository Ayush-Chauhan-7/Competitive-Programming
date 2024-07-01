    // https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
    
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

    const int mod = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,ll>> adj[n];
        for(auto i:roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        vector<ll> dist(n,1e18),ways(n);
        dist[0] = 0;
        ways[0] = 1;
        q.push({0,0});
        while(!q.empty())
        {
            auto [dis,u] = q.top();
            q.pop();
            if(dis!=dist[u])
                continue;
            for(auto [v,wt]:adj[u])
            {
                ll newDis = dis + wt;
                if(newDis< dist[v])
                {
                    dist[v] = newDis;
                    ways[v] = ways[u];
                    q.push({newDis,v});
                }
                else if(newDis==dist[v])
                    ways[v] = (ways[v]+ways[u])%mod;
            }
        }
        return ways[n-1];
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