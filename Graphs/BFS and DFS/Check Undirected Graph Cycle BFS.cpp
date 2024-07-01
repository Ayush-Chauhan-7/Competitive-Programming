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
    
    bool bfs(int src, vector<int> adj[])
    {
        vis[src] = true;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i: adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    q.push({i,node});
                }
                else if(i!=parent)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        vis.resize(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(bfs(i,adj))
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