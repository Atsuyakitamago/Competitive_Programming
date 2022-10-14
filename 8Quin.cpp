#include <stdio.h>
#include <string.h>

#define N 10

vector<int> queen(N);
vector<vector<int>> board(N. vector<int>(N, 0));



/* (i,j)の位置から縦横斜めの方向にある board のすべての要素の値に dを加える */
void changeBoard(int i, int j, int d)
{
    
    //縦方向 上
    for(int a=i+1; a<N; a++){
        board[a][j] += d;
    }

    //右斜め上
    for(int a=1; a<n; a++){
        if(i+a<n && j+a<n){
            board[i+a][j+a] +=d;
        }
    }

    //左斜め上
    for(int a=1; a<n; a++){
        if(i+a<n && j-a>=0){
            board[i+a][j-a] +=d;
        }
    }
}

/* i 行目のクイーンの位置を設定して， setQueen(queen, board, i+1) を呼び出す
　ただし， i == N のときは，一つの解が queen に入っているのでそれを表示するだけである */
void setQueen(int i)
{

    if (i == N)
    { /* 解が見つかった */
        printQueen(queen);
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (board[i][j] == 0)
        {                                  /* (i,j) の位置に置けるならば */
            queen[i] = j;                  /* (i,j) の位置にクイーンを置く */
            changeBoard(i, j, 1);  /* (i,j) から縦横斜めの方向のboard値を+1する */
            setQueen(i + 1); /* i+1 行目のクイーンの位置を決める */
            changeBoard(i, j, -1);  /* (i,j) から縦横斜めの方向のboard値を元に戻す */
        }
    }
}


int main()
{
    setQueen(0);
    return 0;
}