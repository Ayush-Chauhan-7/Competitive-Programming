    //https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B
    
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

    bool cost(vi &a, ll n, ll k, ll sum)
    {
        ll c = 1, dum=0;
        fo(i,n)
        {
            if(dum + a[i]>sum)
            {
                c++;
                dum=a[i];
            }
            else
                dum += a[i];
        }
        return c<=k;
    }

    void solve()
    {
        ll n,k;
        cin>>n>>k;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        ll low = *max_element(a.begin(),a.end());
        ll high = 0;
        fo(i,n)
            high += a[i];
        while(low<=high)
        {
            ll mid = high + (low-high)/2;
            if(cost(a,n,k,mid))
                high = mid-1;
            else
                low = mid+1;
        }
        cout<<low<<endl;
    
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