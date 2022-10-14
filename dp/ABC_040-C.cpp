#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
#define popcount __builtin_popcount
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define loop(i,a,b) for(int i=a;i<(b);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int a[100000],dp[100000];

int main(){
  cin.tie(0);ios::sync_with_stdio(0);
  int n;cin>>n;
  rep(i,n)cin>>a[i];
  dp[1]=abs(a[1]-a[0]);
  loop(i,2,n)dp[i]=min(abs(a[i]-a[i-1])+dp[i-1],abs(a[i]-a[i-2])+dp[i-2]);
  cout<<dp[n-1];
}