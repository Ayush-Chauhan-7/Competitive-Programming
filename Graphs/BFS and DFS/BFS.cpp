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

    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int> bfs, vis(n,0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i: adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return bfs;
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