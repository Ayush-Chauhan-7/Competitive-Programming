    // Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
    
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


    bool cost(double x, double c)
    {
        double ans = x*x + sqrtl(x);
        return ans>=c;
    }

    void solve()
    {
        double c;
        cin>>c;
        double low = 0, high = c;
        ll i = 0;
        while(low<high && i<100)
        {
            double mid = (low+high)/2;
            if(cost(mid,c))
                high = mid;
            else
                low = mid;
            i++;
        }
        cout<<setprecision(20)<<low;
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