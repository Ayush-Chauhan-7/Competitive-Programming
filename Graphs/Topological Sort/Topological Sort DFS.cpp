    // https://www.geeksforgeeks.org/problems/topological-sort/1
    
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

    vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> topSort, vis(n,0);
	    auto dfs = [&](int u, auto&& dfs) -> void
	    {
	        vis[u] = 1;
	        for(auto v:adj[u])
	            if(!vis[v])
	                dfs(v,dfs);
            topSort.push_back(u);
	    };
	    for(int i=0;i<n;i++)
	       if(!vis[i])
	            dfs(i,dfs);
        reverse(topSort.begin(),topSort.end());
        return topSort;
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