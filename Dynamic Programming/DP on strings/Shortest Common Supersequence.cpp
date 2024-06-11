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


    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(); 
        int m=s2.size();
        int t[n+1][m+1]; //table generated while computing LCS length
        string res; // result	
        // compute LCS length using tabulation      
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }     
        //print lcs
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]>t[i][j-1])
                {
                    res.push_back(s1[i-1]);
                    i--;
                } else{
                    res.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i>0) // if s1 characters are still left
        {
            res.push_back(s1[i-1]);
            i--;
        }
        while(j>0) //if s2 characters are still left
        {
            res.push_back(s2[j-1]);
            j--;
            
        }
            reverse(res.begin(),res.end()); 
            return res;
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