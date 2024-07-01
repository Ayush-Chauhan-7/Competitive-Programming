    // https://leetcode.com/problems/find-eventual-safe-states/
    
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

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> safe, in(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            in[i] = graph[i].size();
            if(!in[i])
                q.push(i);
            for(int j:graph[i])
                adj[j].push_back(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto i:adj[node])
            {
                in[i]--;
                if(!in[i])
                    q.push(i);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
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