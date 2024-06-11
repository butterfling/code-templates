#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h> 
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef long double lld;
const int N=1e5+7;
vector<int> primes;
vector<bool> prime(N+1,true);
 
void sieve(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(prime[i]){
            primes.push_back(i);
            for(ll j=(ll)i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i = static_cast<int>(sqrt(N)) + 1; i <= N; i++) {
        if(prime[i]){
            primes.push_back(i);
        }
    }
}

bool checkRange(vector<int>&a,vector<int>&b,int l,int r, int n){
    
    bool pref=true,suff=true;

    for(int i=0;i<l;i++){
        if(a[i]!=b[i]){
            pref = false;
            break;
        }
    }

    for(int j=r+1;j<n;j++){
        if(a[j]!=b[j]){
            suff=false;
            break;
        }
    }

    return pref&&suff;

}

void solve() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>>pref(n+1,vector<int>(m+1,0));


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j]=mat[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<pref[x][y]<<nline;
    }
    
}

signed main(){
    solve();
}