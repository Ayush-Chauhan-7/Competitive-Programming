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
        set<pair<int,int>> st;;
        dist[S] = 0;
        st.insert({0,S});
        while(st.size())
        {
            auto x = st.begin();
            int u = x->second;
            st.erase(x);
            for(auto i: adj[u])
            {
                int v = i[0], wt = i[1];
                if(dist[u]+wt < dist[v])
                {
                    st.erase({dist[v],v});
                    dist[v] = dist[u] + wt;
                    st.insert({dist[v],v});
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