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
        ll n, c1,c2,c3,p1=0,p2=0,p3=0;
        cin>>n;
        fo(i,n)
        {
            cin>>c1>>c2>>c3;
            c1 += max(p2,p3);
            c2 += max(p1,p3);
            c3 += max(p1,p2);
            p1=c1, p2=c2, p3=c3;
        }
        cout<<max(max(p1,p2),p3)<<endl;
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