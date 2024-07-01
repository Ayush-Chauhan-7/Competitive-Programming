    // https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
    
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

    void shortest_distance(vector<vector<int>>&d){
	    int n = d.size(), INF = -1;
	    for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] != INF && d[k][j] != INF)
                    {
                        if(d[i][j]==INF)
                            d[i][j] = d[i][k] + d[k][j];
                        else
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                    }
                }
            }
        }
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