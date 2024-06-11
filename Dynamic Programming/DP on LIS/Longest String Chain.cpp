    // https://leetcode.com/problems/longest-string-chain/description/
    
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


    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0;
        int second = 0;
        
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }

    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }


    int longestStrChain(vector<string>& arr){

        int n = arr.size();
        sort(arr.begin(), arr.end(),comp);
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0; i<=n-1; i++){  
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){      
                if( compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                }
            }
            if(dp[i] > maxi)
                maxi = dp[i];
        }
        return maxi;
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