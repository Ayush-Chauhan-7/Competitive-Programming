    // https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
    
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

    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,0});
        int ans = 0;
        vector<int> vis(n,0);
        while(!q.empty())
        {
            int wt = q.top().first;
            int u = q.top().second;
            q.pop();
            if(vis[u])
                continue;
            vis[u] = 1;
            ans += wt;
            for(auto i: adj[u])
            {
                int v = i[0];
                int edw = i[1];
                if(!vis[v])
                    q.push({edw,v});
            }
        }
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