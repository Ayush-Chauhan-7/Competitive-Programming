    // https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
    
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

    vector<int> fin,vis;
	
	void dfs(int node, vector<vector<int>>& adj)
	{
	    vis[node]=1;
	    for(auto i:adj[node])
	    {
	        if(!vis[i])
	           dfs(i,adj);
	    }
	    fin.push_back(node);
	}
	
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vis.resize(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,adj);
        }
        vector<vector<int>> revadj(n);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
                revadj[it].push_back(i);
        }
        vis.clear();
        vis.resize(n,0);
        vector<int> ord = fin;
        int scc=0;
        reverse(ord.begin(),ord.end());
        for(auto i:ord)
        {
            if(!vis[i])
            {
                scc++;
                dfs(i,revadj);
            }
        }
        return scc;
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