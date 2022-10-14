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
    
    int N, K;
    cin >> N >> K;

    vector<int> h(N+1);

    for(int i=1; i<=N; i++){
        cin >> h.at(i);
    }
    // 要素数は10^5+1 最初のdp[0]は使わないため
    int dp[100001];

    dp[1] = 0;


    for(int i=2; i<=N; i++){
        for(int j=1; j<=K; j++){
            
            // iのK個手前まで全て調べたいが, そもそもiが小さい場合は i-jが1より小さくなる前にbreakする必要がある.
            if(i-j>=1){
                // jが1の場合は最初で比較対象がないので, dp[i]にそのまま格納する
                if(j==1) dp[i] = dp[i-1] + abs(h.at(i) - h.at(i-1));
                // いままでのdp[i] より小さければ更新
                else{
                    dp[i] = min(dp[i], dp[i-j] + abs(h.at(i) - h.at(i-j)));
                }
            }
            else{
                break;
            }
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
