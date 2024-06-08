    //Problem Link: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
    
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
        ll n,k;
        cin>>n>>k;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        ll x;
        fo(i,k)
        {
            cin>>x;
            ll ind = lower_bound(a.begin(),a.end(),x) - a.begin();
            cout<<ind+1<<endl;
        }
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