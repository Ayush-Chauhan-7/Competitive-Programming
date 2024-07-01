    // https://leetcode.com/problems/is-graph-bipartite/
    
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

    vector<int> vis;
    
    bool bfs(int src, vector<vector<int>>& adj)
    {
        vis[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i: adj[node])
            {
                if(vis[i]==-1)
                {
                    vis[i] = 1-vis[node];
                    q.push(i);
                }
                else if(vis[i]==vis[node])
                    return true;
            }
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(bfs(i,graph))
                    return false;
            }
        }
        return true;
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