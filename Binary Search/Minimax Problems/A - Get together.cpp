    // Problem Link: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
    
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

    bool cost(vi &x, vi &v, ll n, double t)
    {
        double mini = -1e18, maxi = 1e18;
        fo(i,n)
        {
            mini = max(mini, x[i] - v[i]*t);
            maxi = min(maxi, x[i] + v[i]*t);
        }
        return mini<=maxi;
    }

    void solve()
    {
        ll n;
        cin>>n;
        vi x(n),v(n);
        fo(i,n)
            cin>>x[i]>>v[i];
        double low = 0, high = 1e10;
        ll i=0;
        while(low<=high && i<100)
        {
            i++;
            double mid = low + (high-low)/2;
            if(cost(x,v,n,mid))
                high = mid;
            else
                low = mid;
        }
        cout<<setprecision(10)<<low<<endl;
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