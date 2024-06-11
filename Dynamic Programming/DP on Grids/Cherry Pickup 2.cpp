    // https://leetcode.com/problems/cherry-pickup-ii/
    
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


    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r+1, vector<vector<int>>(c,vector<int>(c,0)));
        for(int i=r-1;i>=0;i--)
        {
            for(int j1=0;j1<c;j1++)
            {
                for(int j2=0;j2<c;j2++)
                {
                    int maxi = -1e9;
                    for(int j11=max(j1-1,0);j11<=min(j1+1,c-1);j11++)
                    {
                        for(int j22=max(j2-1,0);j22<=min(j2+1,c-1);j22++)
                            maxi = max(maxi, dp[i+1][j11][j22]);
                    }
                    int val;
                    if(j1==j2)
                        val = grid[i][j1];
                    else
                        val = grid[i][j1] + grid[i][j2];
                    dp[i][j1][j2] = maxi + val;
                }
            }
        }
        return dp[0][0][c-1];
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