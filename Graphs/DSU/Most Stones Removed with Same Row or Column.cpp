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

    vector<int> p,sz;

    void init(int n)
    {
        p.resize(n);
        sz.assign(n,1);
        iota(p.begin(),p.end(),0);
    }

    int find(int x)
    {
        while(x != p[x])
            x = p[x] = p[p[x]];
        return x;
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)
            return false;
        if(sz[x]<sz[y])
            swap(x,y);
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }

    int removeStones(vector<vector<int>>& stones) {
        int r=0,c=0,ans=stones.size();
        for(auto i:stones)
        {
            r = max(r,i[0]+1);
            c = max(c,i[1]+1);
        }
        init(r+c);
        vector<int> vis(r+c);
        for(auto i:stones)
        {
            unite(i[0],r+i[1]);
            vis[i[0]] = 1;
            vis[r+i[1]] = 1;
        }
        for(int i=0;i<r+c;i++)
            if(vis[i] && p[i]==i)
                ans--;
        return ans;
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