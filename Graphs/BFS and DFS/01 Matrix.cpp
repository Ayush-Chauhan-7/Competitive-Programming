    // https://leetcode.com/problems/01-matrix/
    
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

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> d = {0,-1,0,1,0};
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                    q.push({i,j});
                else
                    mat[i][j] = -1;
            }
        }
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int rr = r + d[i];
                int cc = c + d[i+1];
                if(rr<0 || rr==n || cc<0 || cc==m || mat[rr][cc]!=-1)
                    continue;
                mat[rr][cc] = mat[r][c] + 1;
                q.push({rr,cc});
            }
        }
        return mat;
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