    // Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
    
    #include <bits/stdc++.h>
    typedef unsigned long long ll;
    #define fo(i, n) for(ll i=0;i<n;i++)
    #define vi vector<ll>
    #define vp vector< pair <ll,ll> >
    #define f first
    #define s second
    #define pb push_back
    #define endl '\n'

    using namespace std;

    bool cost(vi &a, ll n, double x, ll k)
    {
        ll c=0;
        fo(i,n)
        {
            c += floor(a[i]/x);
            if(c>=k)
                return true;
        }
        return false;
    }

    void solve()
    {
        ll n,k;
        cin>>n>>k;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        sort(a.begin(),a.end());
        double low = 0, high = 1e7+1;
        int i=0;
        while(low<high && i<50)
        {
            double mid = low + (high-low)/2;
            if(cost(a,n,mid,k))
                low = mid;
            else
                high = mid;
            i++;
        }
        cout<<setprecision(7)<<high<<endl;
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