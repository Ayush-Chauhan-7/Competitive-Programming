    //Problem Link: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
    
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
        ll n;
        cin>>n;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        sort(a.begin(),a.end());
        ll x,y,k;
        cin>>k;
        fo(i,k)
        {
            cin>>x>>y;
            ll ind1 = lower_bound(a.begin(),a.end(),x) - a.begin();
            ll ind2 = upper_bound(a.begin(),a.end(),y) - a.begin()-1;
            cout<<ind2-ind1+1<<" ";
        }
        cout<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        // ll t;
        // cin>>t;
        // while(t--)
            solve();
        return 0;
    }