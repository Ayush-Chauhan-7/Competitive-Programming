    // https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
    
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

    vector<bool> vis;
    
    bool dfs(int u, int p, vector<int> adj[])
    {
        vis[u] = true;
        for(auto v: adj[u])
        {
            if(!vis[v])
            {
                if(dfs(v,u,adj))
                    return true;
            }
            else if(v!=p)
                return true;
        }
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        vis.resize(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj))
                    return true;
            }
        }
        return false;
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