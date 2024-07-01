    // https://leetcode.com/problems/course-schedule/
    
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

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], vis(n,0);
        for(auto i:edges)
            adj[i[0]].push_back(i[1]);
        auto dfs = [&](int u, auto&& dfs) -> bool
        {
            vis[u] = 2;
            for(auto v:adj[u])
            {
                if(!vis[v])
                {
                    if(dfs(v,dfs))
                        return true;
                }
                else if(vis[v]==2)
                    return true;
            }
            vis[u] = 1;
            return false;
        };
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,dfs))
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