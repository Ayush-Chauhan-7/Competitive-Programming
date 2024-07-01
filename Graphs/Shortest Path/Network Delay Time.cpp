    // https://leetcode.com/problems/network-delay-time/
    
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

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i:times)
            adj[i[0]-1].push_back({i[1]-1,i[2]});
        vector<int> dist(n,1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[k-1] = 0;
        q.push({0,k-1});
        while(!q.empty())
        {
            auto [dis,node] = q.top();
            q.pop();
            if(dis!=dist[node])
                continue;
            for(auto i:adj[node])
            {
                int v = i.first, wt = i.second;
                if(dis + wt < dist[v])
                {
                    dist[v] = dis + wt;
                    q.push({dist[v],v});
                }
            }
        }
        int ans = *max_element(dist.begin(),dist.end());
        if(ans==1e9)
            return -1;
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