    // https://codeforces.com/contest/1370/problem/B
    
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
        ll n,x;
        cin>>n;
        ll even=0,odd=0,c=0;
        fo(i,2*n)
        {
            cin>>x;
            if(x%2)
            {
                if(odd && c<n-1)
                {
                    cout<<odd<<" "<<i+1<<endl;
                    odd = 0;
                    c++;
                }
                else
                    odd = i+1;
            }
            else
            {
                if(even && c<n-1)
                {
                    cout<<even<<" "<<i+1<<endl;
                    even = 0;
                    c++;
                }
                else
                    even = i+1;
            }
        }
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ll t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }