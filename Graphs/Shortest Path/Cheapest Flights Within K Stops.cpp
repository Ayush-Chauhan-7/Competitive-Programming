    // https://leetcode.com/problems/cheapest-flights-within-k-stops/
    
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

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        queue<vector<int>> q;
        q.push({0, src, 0});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            int u = x[1];
            int stops = x[0];
            int dis = x[2];
            if(stops>k)
                continue;
            for(auto i:graph[u])
            {
                int v = i.first, wt = i.second;
                if(dis + wt < dist[v])
                {
                    dist[v] = dis + wt;
                    q.push({stops+1,v,dist[v]});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
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