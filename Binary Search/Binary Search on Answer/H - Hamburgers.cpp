    //Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
    
    #include <bits/stdc++.h>
    typedef long long ll;
    using namespace std;
    bool cost(ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll rb, ll rs, ll rc, ll r, ll x)
    {
        ll bb = max(x*rb - nb, ll(0));
        bb*=pb;
        ll cc = max(x*rc - nc, ll(0));
        cc*=pc;
        ll ss = max(x*rs - ns, ll(0));
        ss*=ps;
        ll count = (bb + cc + ss);
        return count<=r;
    }

    void solve()
    {
        string s;
        cin>>s;
        ll nb,ns,nc;
        cin>>nb>>ns>>nc;
        ll pb,ps,pc;
        cin>>pb>>ps>>pc;
        ll r;
        cin>>r;
        ll rb=0, rs=0, rc=0;
        for(auto x:s)
        {
            if(x=='B')
                rb++;
            else if(x=='C')
                rc++;
            else
                rs++;
        }
        ll low = -1, high = nb + ns + nc + 1 + r;
        while(low<=high)
        {
            ll mid = (low+high)/2;
            if(cost(nb, ns, nc, pb, ps, pc, rb, rs, rc, r, mid))
                low = mid+1;
            else
                high = mid-1;
        }
        cout<<high<<endl;
    }

    int main()
    {
        solve();
        return 0;
    }