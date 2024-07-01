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

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n]; 
        vector<int> dist(n,1e9), parent(n,-1),path;
        for(int i=0;i<n;i++)
            parent[i] = i;
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            u--; v--;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty())
        {
            int u = q.top().second;
            int dis = q.top().first;
            q.pop();
            if(dis!=dist[u])
                continue;
            for(auto i:adj[u])
            {
                int v = i.first, wt = i.second;
                if(dis+wt<dist[v])
                {
                    dist[v] = dis+wt;
                    parent[v] = u;
                    q.push({dist[v],v});
                }
            }
        }
        int node= n-1;
        while(parent[node]!=node)
        {
            path.push_back(node+1);
            node = parent[node];
        }
        path.push_back(node+1);
        reverse(path.begin(),path.end());
        return path;
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