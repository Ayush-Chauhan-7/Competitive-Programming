    // https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
    
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

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++)
            d[i][i] = 0;
        for(auto i:edges)
        {
            d[i[0]][i[1]] = i[2];
            d[i[1]][i[0]] = i[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        int ans,c=0,mini=n+1;
        for(int i=0;i<n;i++)
        {
            c=0;
            for(int j=0;j<n;j++)
            {
                if(d[i][j] <= distanceThreshold)
                    c++;
            }
            if(c<=mini)
            {
                mini = c;
                ans = i;
            }
        }
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