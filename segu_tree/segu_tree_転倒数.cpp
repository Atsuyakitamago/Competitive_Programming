
//参考URL
// https://www.creativ.xyz/segment-tree-entrance-999/

// https://atcoder.jp/contests/chokudai_S001/submissions/9285044

//数列 a をバブルソートした時、スワップが何回発生するかを出力しなさい。という問題に対する解答


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFl (1LL<<60)
#define rep(i, n) for(int i = 0; i < (n); ++i)


vector<ll> value; // ノードの値を持つ配列
int N; // 葉の数

void update(int i, ll x) {
    // i 番目の葉の値を x に変える
    i += N - 1; // i 番目の葉のノード番号
    value[i] = x;
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        value[i] = value[i * 2 + 1] + value[i * 2 + 2]; // 左右の子の 和 を計算しなおす
    }
}

//RMQ 指定区間の最小値を得るクエリ 親から子に聞く
ll query(int a, int b, int k, int l, int r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return 0; // 区間が被らない場合は 単位元 を返す
    if (a <= l && r <= b)
        return value[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
    else {
        // 一部だけ範囲が被る場合は左右の子に委託する
        //ノードiの子ノードは2*i+1,2*i+2で得られる
        ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
        return c1+c2; // 左右の子の値の min を取る
    }
}

int main(void) {
    int n; // 数列のサイズとクエリの数
    cin >> n;
    N = 1;
    while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）

    //必要なノードの数は N + N-1=2N-1  葉の数はNで, それ以外の部分は等比数列の和の公式から求めてN-1個だから
    value = vector<ll>(2 * N - 1, 0);

    vector<ll> A(n);
    ll x;


    rep(i, n){
        cin >> x;
        A[x-1]=i;
    }

    reverse(A.begin(), A.end());


    ll ans=0;

    rep(i, n){
        ans += query(0, A[i], 0, 0, N);
        update(A[i], 1);
    }

    cout << ans << endl;
    
}