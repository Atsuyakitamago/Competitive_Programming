// _GLIBCXX_DEBUGは priority queue と一緒に使ってはいけない
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define loop(i,a,b) for(int i=a;i<(b);i++)

#define PI 3.14159265358979323846
#define INFl (1LL<<60)
#define INFi (1 << 30)

using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vecPi = vector<pair<int, int>>;
using vecPl = vector<pair<ll, ll>>;
using veci = vector<int>;
using vecl = vector<ll>;
using vecs = vector<string>;
using mapi = map<int, int>;
using mapl = map<ll, ll>;
using seti = set<int>;
using setl = set<ll>;

// 上下左右
vector<int> dx{ 0, 1, 0, -1 }, dy{ -1, 0, 1, 0 };

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 上記のmodpow関数を使って a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

// エラトステネスの篩  1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 1 は予めふるい落としておく
    isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}


// 素因数分解
vector<int> pfact(int x){
    vector<int> res;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            res.push_back(i);
        }
    }
    if(x!=1){res.push_back(x);}
    return res;
}


int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}


#define MOD int(1e9+7)

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

// nCr を計算する関数
ll nCr(ll n, ll r){

    ll cnt=1;

    rep(i, r){
        cnt *= (n-i);
        cnt%=MOD;
    }

    //毎度 MODで余りをとっているため (r-i)で割り切れるとは限らない。よって cnt /= (r-i) というやり方でやってはだめ
    rep(i, r){
        cnt %= MOD;
        cnt *= modinv(r-i, MOD);
    }
    return cnt;
}

// seg tree class
template <class T>
class SegTree {
    int n;                       // 葉の数
    vector<T> data;              // データを格納するvector
    T def;                       // 初期値かつ単位元
    function<T(T, T)> operation; // 区間クエリで使う処理
    function<T(T, T)> update;    // 点更新で使う処理

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない
        if (a <= l && r <= b)
            return data[k]; // a,l,r,bの順で完全に含まれる
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
            return operation(c1, c2);
        }
    }

    public:
    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:更新関数
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
            function<T(T, T)> _update)
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }

    // 場所i(0-indexed)の値をxで更新
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    // [a, b)の区間クエリを実行
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    // 添字でアクセス
    T operator[](int i) {
        return data[i + n - 1];
    }
};

// 使用例
//SegTree<ll> st(N, (1LL << 31) - 1, [](ll a, ll b) { return min(a, b); }, [](ll a, ll b) { return b; });

// a^n
ll fastpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main(){
    
    return 0;
}