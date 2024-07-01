    // https://leetcode.com/problems/course-schedule-ii/
    
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

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], in(n,0),topSort;
        for(auto i:edges)
        {
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
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
	        topSort.push_back(node);
	        for(auto i:adj[node])
	        {
	            in[i]--;
	            if(!in[i])
	                q.push(i);
	        }
	    }
        if(topSort.size()<n)
            topSort.clear();
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