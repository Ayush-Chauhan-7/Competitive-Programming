    //Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
    
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

    void solve()
    {
        ll w,h,n;
        cin>>w>>h>>n;
        ll low=1, high=max(max(w, h), n * min(h, w));
        while(low<high)
        {
            ll x = (low+high)/2;
            if((x/w)*(x/h)>=n)
                high = x-1;
            else
                low = x+1;
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