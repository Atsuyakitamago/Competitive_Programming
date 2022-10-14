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

int INF = 1 << 30;

int main(){

    string s, t;
    cin >> s >> t;

    int slen = s.size(), tlen = t.size();

    int dp[3002][3002];

    fill( dp[0] , dp[3002], 0);

    rep1(i, slen){
        rep1(j, tlen){

            if(s[i-1] == t[j-1])   dp[i][j] = dp[i-1][j-1] + 1;

            else                   dp[i][j] = max( dp[i-1][j], dp[i][j-1]);

        }
    }

    int len = dp[slen][tlen];

    int i=slen;
    int j = tlen;

    string ans[len+1];

    while(len>0){

        if(s[i-1] == t[j-1]){
            ans[len] = s[i-1];
            i--;
            j--;
            len--;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }

    rep1(i, dp[slen][tlen]){
        cout << ans[i];
    }

    cout << endl;

    return 0;

}