    // https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C
    
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

    bool cost(vi &a, ll n, ll k, ll dist)
    {
        ll prev = a[0];
        k--;
        for(int i=1;i<n && k>0;i++)
        {
            if(a[i]-prev >= dist)
            {
                prev = a[i];
                k--;
            }
        }
        return k==0;
    }

    void solve()
    {
        ll n,k;
        cin>>n>>k;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        ll low = 1, high = a[n-1]-a[0];
        while(low<=high)
        {
            ll mid = low + (high-low)/2;
            if(cost(a,n,k,mid))
                low = mid+1;
            else
                high = mid-1;
        }
        cout<<high<<endl;
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