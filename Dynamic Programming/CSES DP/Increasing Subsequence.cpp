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
        int n,ind;
        cin>>n;
        vi a(n),lis;
        fo(i,n)
            cin>>a[i];
        lis.pb(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>lis.back())
                lis.pb(a[i]);
            else
            {
                ind = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
                lis[ind] = a[i];
            }
        }
        cout<<lis.size()<<endl;
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