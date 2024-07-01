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

    vector<int> ans,vis;
    
    void dfs(int node, vector<int> adj[])
    {
        vis[node] = 1;
        ans.push_back(node);
        for(auto i:adj[node])
        {
            if(!vis[i])
                dfs(i,adj);
        }
    }
    
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vis.resize(n);
        dfs(0,adj);
        return ans;
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