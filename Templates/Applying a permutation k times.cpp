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
    
    vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
        vector<int> newSequence(sequence.size());
        for(int i = 0; i < sequence.size(); i++) {
            newSequence[i] = sequence[permutation[i]];
        }
        return newSequence;
    }

    vector<int> permute(vector<int> sequence, vector<int> permutation, long long k) {
        while (k > 0) {
            if (k & 1) {
                sequence = applyPermutation(sequence, permutation);
            }
            permutation = applyPermutation(permutation, permutation);
            k >>= 1;
        }
        return sequence;
    }

    void solve()
    {
        
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }