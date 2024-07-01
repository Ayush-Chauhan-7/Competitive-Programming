    // https://leetcode.com/problems/number-of-provinces/
    
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

    void dfs(int node, vector<vector<int>>& graph)
    {
        vis[node] = true;
        for(int i=0;i<vis.size();i++)
        {
            if(i!=node && graph[node][i] && !vis[i])
                dfs(i,graph);
        }
    }

    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        if(!n)
            return 0;
        vis.resize(n,false);
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i,graph);
            }
        }
        return c;
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