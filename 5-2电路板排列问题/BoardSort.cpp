#include<iostream>

using namespace std;

class Board{
    friend int Arrangement(int **, int, int, int[]);
    private:
        void Backtrack(int i, int cd);
        int n,
            m,
            *x,
            *bestx,
            bestd,
            *total,
            *now,
            **B;
};

void Board::Backtrack(int i,int cd)
{
    if(i==n)
    {
        for (int j = 1; j <= n;j++)
        {
            bestx[j] = x[j];
        }
        bestd = cd;
    }
    else{
        for (int j = i; j <= n;j++)
        {
            int ld = 0;
            for (int k = 1; k <= m;k++)
            {
                now[k] += B[x[j]][k];
                if(now[k]>0&&total[k]!=now[k])
                    ld++;

            }
            if(cd>ld)
                ld = cd;
            if(ld<bestd){
                swap(x[i], x[j]);
                Backtrack(i + 1, ld);
                swap(x[i], x[j]);
                for (int k = 1; k <= m;k++)
                    now[k] -= B[x[j]][k];
            }
        }

    }
}

int Arrangement(int **B, int n, int m, int bestx[])
{
    Board X;
    X.x = new int[n + 1];
    X.total = new int[m + 1];
    X.now = new int[m + 1];
    X.B = B;
    X.n = n;
    X.m = m;
    X.bestx = bestx;
    X.bestd = m + 1;
    for (int i = 1; i <= m;i++){
        X.total[i] = 0;
        X.now[i] = 0;
    }
    for (int i = 1; i <= n;i++){
        X.x[i] = i;
        for (int j = 1; j <= m;j++){
            X.total[j] += B[i][j];
        }
    }
        X.Backtrack(1,0);
        delete[] X.x;
        delete[] X.total;
        delete[] X.now;
        return X.bestd;
}

int main()
{
    
    return 0;
}