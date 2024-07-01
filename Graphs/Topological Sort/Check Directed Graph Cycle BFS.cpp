    // https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    
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

    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> in(n,0);
        int c=0;
	    for(int i=0;i<n;i++)
	    {
	        for(auto j: adj[i])
	            in[j]++;
	    }
	    queue<int> q;
	    for(int i=0;i<n;i++)
	    {
	        if(!in[i])
	            q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        c++;
	        for(auto i:adj[node])
	        {
	            in[i]--;
	            if(!in[i])
	                q.push(i);
	        }
	    }
	    return c<n;
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