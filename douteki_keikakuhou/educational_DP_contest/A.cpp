// 1次元配列を用いたDP



#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
#define popcount __builtin_popcount
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define loop(i,a,b) for(int i=a;i<(b);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int N;
    cin >> N;

    vector<int> h(N);

    rep(i, N) cin >> h.at(i);

    // dp[i]  足場iまでのコストの最小値

    int dp[100000];

    // 最初は足場1にいるのでコスト0
    dp[0] = 0;
    // 足場1までの最小値は比較対象がないので普通に計算する. 
    dp[1] = abs(h.at(1) - h.at(0));


    loop(i, 2, N) dp[i] = min( dp[i-1] + abs(h.at(i) - h.at(i-1)) , dp[i-2] + abs(h.at(i) - h.at(i-2)) );

    cout << dp[N-1] << endl;

    return 0;
}