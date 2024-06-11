    // https://www.geeksforgeeks.org/problems/geek-jump/1
    
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


    int minimumEnergy(vector<int>& height, int n) {
        int p1=0,p2=0,d1,d2;
        if(n==1)
            return 0;
        for(int i=1;i<n;i++)
        {
            d1 = p1 + abs(height[i]-height[i-1]);
            d2 = INT_MAX;
            if(i>1)
                d2 = p2 + abs(height[i]-height[i-2]);
            p2 = p1;
            p1 = min(d1,d2);
        }
        return p1;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        return 0;
    }