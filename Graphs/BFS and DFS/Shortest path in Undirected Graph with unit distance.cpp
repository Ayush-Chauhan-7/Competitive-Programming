    // https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
    
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

    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int> adj[n],dist(n,-1);
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i:adj[node])
            {
                if(dist[i]==-1)
                {
                    dist[i] = dist[node]+1;
                    q.push(i);
                }
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