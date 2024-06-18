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


    ll sum_of_digits(ll n){
        ll sum = 0;
        while(n){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    ll count(ll n, ll mul){
        if(n <= 0)
            return 0;
        ll sum = 0;
        ll last_digit = n % 10;
        ll rem_part = n / 10;
        sum += ((last_digit * (last_digit + 1) / 2) * mul);
        ll sod = sum_of_digits(rem_part);
        sum += (sod * (last_digit + 1) * mul);
        sum += (rem_part * 45 * mul);
        return sum + count(rem_part - 1, mul * 10);
    }

    void solve()
    {
        ll L,R;
        cin>>L>>R;
        ll ans = count(R,1);
        if(L-1)
            ans-= count(L-1,1);
        cout<<ans<<endl;
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