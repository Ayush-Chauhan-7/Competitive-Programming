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


    void solve()
    {
        ll n,m,f=0;
        cin>>n>>m;
        vector<vi> edges(m,vi(3,0));
        fo(i,m)
        {
            cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
            edges[i][0]--, edges[i][1]--;
        }
        vi dist(n,1e18),p(n,-1),cycle;
        dist[0] = 0;
        ll cycl = -1;
        fo(i,n)
        {
            cycl = -1;
            for(auto x:edges)
            {
                if(dist[x[1]]>dist[x[0]]+x[2])
                {
                    dist[x[1]]=dist[x[0]]+x[2];
                    p[x[1]] = x[0];
                    cycl = x[1];
                }
            }
        }
        if(cycl==-1)
        {
            cout<<"NO"<<endl;
            return;
        }
        int strt = cycl;
        fo(i,n)
        {
            if(p[strt] == -1) break;
            strt = p[strt];
        }
        for(int i = strt;; i = p[i])
        {
            cycle.push_back(i);
            if(i == strt && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        cout<<"YES"<<endl;;
        for(auto c: cycle){
            cout<<c+1<<' ';
        }
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