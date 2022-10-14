#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
#define popcount __builtin_popcount
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define loop(i,a,b) for(int i=a;i<(b);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int N, W;
    cin >> N >> W;

    vector<int> w(N+1);
    vector<int> v(N+1);

    rep1(i, N){
        cin >> w.at(i) >> v.at(i);
    }


    ll dp[N+1][W+1];

    fill( dp[0] , dp[N+1], 0);



    loop(i, 1, N+1){
        loop(j, 0, W+1){

            if(j-w[i] >= 0) dp[i][j] = max( dp[i-1][j] , dp[i-1][j-w[i]] + v[i]);

            // そもそも荷物iの重さが容量を超えている場合
            else  dp[i][j] = dp[i-1][j];

        }
    }

    cout << dp[N][W] << endl;

    return 0;
}
