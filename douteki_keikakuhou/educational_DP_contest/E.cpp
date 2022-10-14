// Dのナップザック問題と同じように見えるが, Wが最大で10^9あるので, 
// Dと同じやり方だと O(NW) になってタイムアウトする. 
// よってボトルネックである重さWでループを回さないことが肝になってくる. 

// 見方によって様々な形の「最適」が見えてくる   


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

ll INF = 1 << 30;

int main(){



    ll N, W;

    cin >> N >> W;

    vector<ll> w(N+1);
    vector<ll> v(N+1);

    rep1(i, N){
        cin >> w.at(i) >> v.at(i);
    }


    ll dp[N+1][100001];

    loop(i, 0, N+1){
        loop(j, 0, 100001){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;


    // dp[i][j]    i番目までの品物を, 価値が（ちょうど）jになるように選ぶときの最小の重さ

    loop(i, 1, N+1){
        loop(j, 0, 100001){
            if(j-v[i] >= 0) dp[i][j]  = min( dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
            //選ばない時
            else dp[i][j] = dp[i-1][j];
        }
    }

    // ans は価値の大きさ      要はこの解き方は, 価値の最大値から見ていき, 一番最初に実現できるやつを探すというやり方 . 
    int ans = 100000;

    while(dp[N][ans] > W) ans--;

    cout << ans << endl;

    return 0;
}
