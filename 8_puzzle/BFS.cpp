#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define loop(i,a,b) for(int i=a;i<(b);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int INF = 1 << 30;

// 要素数
#define N 4
#define N2 N * N

// 上,右,下,左の順でチェックする
static const int dx[4] = {0,1,0,-1};
static const int dy[4] = {-1,0,1,0};
static const char dir[4] = {'u','r','d','l'};

struct Puzzle{
    // 各々のタイルの状態(spaceは0だけど、9に換算する)
    int tiles[N2];
    // 空白の位置を管理indexで0 - 8まで
    int space;
    // 解法までのルートを記録
    string path;
    
    // 同じ状態遷移か判定する
    bool operator < (const Puzzle &p) const {
        for(int i = 0;i < N2;++i){
            if(tiles[i] == p.tiles[i]) continue;
            // 最短を求めるためにタイル数値が大きいと一致していると判定する(上から1,2,3と並ぶので)
            return tiles[i] > p.tiles[i];
        }
        return false;
    }
};

/**
    パズルの一致チェック
*/
bool isCorrect(Puzzle p){
    // パズルが順番通り一致しているかチェック
    for(int i = 0;i < N2;++i){
        // 1,2,3,4,5,6,7,8の順で並ぶ
        if(p.tiles[i] != (i + 1)){
          return false;
        }
    }
    return true;
}

// 幅優先探索を行う
string bfs(Puzzle p){
    // queueを使って、パズルの状態遷移を管理する
    queue<Puzzle> Q;
    // 同じ遷移状態がないか判定するためにmapを定義する
    map<Puzzle, bool> V;
    Puzzle u,v;
    p.path = "";
    Q.push(p);
    // 最初の状態遷移を保存
    V[p] = true;
    
    // 幅優先探索
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        
        // 正解チェック
        if(isCorrect(u)){
            return u.path;
        }
        // 空白の位置を算出する
        int sx = u.space % N;
        int sy = u.space / N;
        
        // スペースの周りの四方のタイルを動かす
        for(int r = 0;r < 4;++r){
            // 動かすタイルのindexを算出する(上,右,下,左の順)
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            // 範囲外チェック
            if(tx < 0 || ty < 0 || tx >= N || ty >= N){
                continue;
            }
            v = u;
            // 入れ替え
            swap(v.tiles[u.space],v.tiles[ty * N + tx]);
            // 入れ替えた場所がspaceになる
            v.space = (ty * N) + tx;
            
            // 同じ状態がでなかったら
            if(!V[v]){
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}

int main(){
    Puzzle in;
    
    for(int i = 0;i < N2;++i){
        cin >> in.tiles[i];
        if(in.tiles[i] == 0){
            // 空白は16として管理
            in.tiles[i] = N2;
            in.space = i;
        }
    }
    
    string answer = bfs(in);
    cout << answer.size() << endl;
    
    return 0;
}