    // https://www.geeksforgeeks.org/problems/alien-dictionary/1
    
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


    string findOrder(string dict[], int N, int n) {
        vector<int> adj[n], in(n,0);
        string  a,b,topSort="";
        for(int i=0;i<N-1;i++)
        {
            a = dict[i];
            b = dict[i+1];
            for(int j=0;j<min(a.size(),b.size());j++)
            {
                if(a[j]!=b[j])
                {
                    int u = a[j]-'a';
                    int v = b[j]-'a';
                    adj[u].push_back(v);
                    break;
                }
            }
        }
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
	        char x = node + 'a';
	        topSort += x;
	        for(auto i:adj[node])
	        {
	            in[i]--;
	            if(!in[i])
	                q.push(i);
	        }
	    }
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