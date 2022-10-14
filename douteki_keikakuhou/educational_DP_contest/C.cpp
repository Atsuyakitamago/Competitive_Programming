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
    int N;
    cin >> N;

    vector<int> a(N+1), b(N+1), c(N+1);
    
    rep1(i, N){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    // 例えば Aにはi日目で, Aを行う時の幸福度の最大値を格納 前日の活動が B または C に限定されることを利用する
    int A, B, C;

    // 初期値は一日目の幸福度をそのまま代入するだけ
    A = a.at(1);
    B = b.at(1);
    C = c.at(1);

    // 一次的にA, B, Cの値を保存しておく変数
    int Ad, Bd, Cd;

    loop(i, 2, N+1){
        // Ad は Aのdummyの意味
        Ad =A; Bd =B; Cd=C;
        //A
        if(Bd>Cd){
            A = Bd + a.at(i);
        }else{
            A = Cd + a.at(i);
        }
        //B
        if(Ad>Cd){
            B = Ad + b.at(i);
        }else{
            B = Cd + b.at(i);
        }
        //C
        if(Ad>Bd){
            C = Ad + c.at(i);
        }else{
            C = Bd + c.at(i);
        }
    }

    if(A >= B) cout << max(A, C);
    else cout << max(B, C);

    return 0;
}