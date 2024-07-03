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

    vector<int> adj(200005, -1);
    int cycle = 0;
    vector<int> visited(200005,0);
    vector<int> ans(200005,0);
    vector<int> path;
    
    
    void dfs(int i){
        path.push_back(i);
        if(visited[i])
            cycle+= ans[i];
        else{
            visited[i] = true;
            cycle++;
            int child = adj[i];
            dfs(child);
        }
    }


    void solve()
    {
        int n;
        cin >> n;
        for(int i =1;i<=n;i++){
            int x;
            cin >> x;
            adj[i] = x;
        }
        for(int i =1; i<=n;i++){
            if(!visited[i]){
                cycle = 0;
                dfs(i);
                bool dec = true;
                reverse(path.begin(),path.end());
                while(path.size() != 0){
                    if(path.front() == path.back()) 
                        dec = false;
                    ans[path.back()] = cycle;
                    if(dec) 
                        cycle--;
                    path.pop_back();
                }
            }
        }
        for(int i = 1;i<=n;i++)
            cout << ans[i] << " ";
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }