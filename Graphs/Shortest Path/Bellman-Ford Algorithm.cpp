    // https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
    
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

    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n,1e8);
        dist[src] = 0;
        for(int i=0;i<n-1;i++)
        {
            for(auto i: edges)
            {
                int u = i[0];
                int v = i[1];
                int wt = i[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        // Nth relaxation to check negative weight cycle
        for(auto i: edges)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                return {-1};
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
        solve();
        return 0;
    }