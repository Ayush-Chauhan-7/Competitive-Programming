    // https://www.geeksforgeeks.org/problems/articulation-point-1/1
    
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

    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n), in(n), low(n),points(n),ans;
        int timer=1;
        auto dfs = [&](int u, int p, auto&& dfs) -> void
        {
            vis[u] = 1;
            in[u] = low[u] = timer;
            timer++;
            int child=0;
            for(auto v:adj[u])
            {
                if(v==p)
                    continue;
                if(!vis[v])
                {
                    dfs(v,u,dfs);
                    low[u] = min(low[u],low[v]);
                    child++;
                    if(low[v]>=in[u] && p!=-1)
                        points[u] = 1;
                }
                else
                    low[u] = min(low[u],in[v]);
            }
            if(p==-1 && child>1)
                points[u] = 1;;
        };
        dfs(0,-1,dfs);
        for(int i=0;i<n;i++)
            if(points[i])
                ans.push_back(i);
        if(!ans.size())
            return {-1};
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