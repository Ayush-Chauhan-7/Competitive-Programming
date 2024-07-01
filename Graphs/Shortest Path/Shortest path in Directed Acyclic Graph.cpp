    // https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
    
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

    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<int> dist(n,-1),  in(n,0), ord;
        vector<pair<int,int>> adj[n];
        queue<int> q;
        int flag=0;
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            in[v]++;
        }
        for(int i=0;i<n;i++)
            if(!in[i])
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(node==0)
                flag=1;
            if(flag)
                ord.push_back(node);
            for(auto it:adj[node])
            {
                int i = it.first;
                in[i]--;
                if(!in[i])
                    q.push(i);
            }
        }
        dist[0] = 0;
        for(auto u:ord)
        {
            if(dist[u]==-1)
                continue;
            for(auto i:adj[u])
            {
                int v = i.first;
                int wt = i.second;
                if(dist[v]==-1 || dist[u]+wt<dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        return dist;
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