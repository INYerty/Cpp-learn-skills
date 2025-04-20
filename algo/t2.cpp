#include <bits/stdc++.h>
using namespace std;

int tile = 1;
vector<vector<int>> board;

void cover(int tr, int tc, int dr, int dc, int size) {
    if(size == 1) return;

    int t = tile++;
    int mid = size / 2;
    
    int special_r[4], special_c[4];
    
    if(dr < tr + mid && dc < tc + mid) {
        special_r[0] = dr; special_c[0] = dc;
    } else {
        special_r[0] = tr + mid - 1; special_c[0] = tc + mid - 1;
        board[tr + mid - 1][tc + mid - 1] = t;
    }
    if(dr < tr + mid && dc >= tc + mid) {
        special_r[1] = dr; special_c[1] = dc;
    } else {
        special_r[1] = tr + mid - 1; special_c[1] = tc + mid;
        board[tr + mid - 1][tc + mid] = t;
    }
    if(dr >= tr + mid && dc < tc + mid) {
        special_r[2] = dr; special_c[2] = dc;
    } else {
        special_r[2] = tr + mid; special_c[2] = tc + mid - 1;
        board[tr + mid][tc + mid - 1] = t;
    }
    if(dr >= tr + mid && dc >= tc + mid) {
        special_r[3] = dr; special_c[3] = dc;
    } else {
        special_r[3] = tr + mid; special_c[3] = tc + mid;
        board[tr + mid][tc + mid] = t;
    }

    cover(tr, tc, special_r[0], special_c[0], mid);
    cover(tr, tc + mid, special_r[1], special_c[1], mid);
    cover(tr + mid, tc, special_r[2], special_c[2], mid);
    cover(tr + mid, tc + mid, special_r[3], special_c[3], mid);
}

int main(){
    int k, dr, dc;
    cin >> k >> dr >> dc;
    int n = 1 << k;  // 棋盘边长 = 2^k
    board.assign(n, vector<int>(n, 0));

    cover(0, 0, dr, dc, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

