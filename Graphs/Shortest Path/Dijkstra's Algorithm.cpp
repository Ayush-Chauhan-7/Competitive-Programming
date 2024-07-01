    // https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
    
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

    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(n,1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[S] = 0;
        q.push({0,S});
        while(!q.empty())
        {
            int u = q.top().second;
            int dis = q.top().first;
            q.pop();
            if(dis!=dist[u])
                continue;
            for(auto i: adj[u])
            {
                int v = i[0];
                int wt = i[1];
                if(dis + wt < dist[v])
                {
                    dist[v] = dis+wt;
                    q.push({dist[v],v});
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