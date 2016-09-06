#include<iostream>
#include "QueueAsList.h"
using namespace std;
struct pair {
    int x,y;
};
bool isValidXandY(int x, int y, int mat[][5], int N, int M) {
    if (x < 0 || y < 0 || x >= N || y >= M || mat[x][y] != 0) {
        return false;
    }
    return true;
}
int minStepsRatInAMaze(int startx, int starty, int endx, int endy, int mat[][5], int N, int M) {
    mat[startx][starty] = 1;
    Queue<pair> Q;
    pair p = { startx, starty};
    Q.enqueue(p);
    int diff[][2] = { {1,0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!Q.isEmpty()) {
        pair current = Q.front();
        int x = current.x, y = current.y;
        Q.dequeue();
        for (int i =0 ; i < 4; i++) {
            int newx = x+diff[i][0], newy = y+diff[i][1];
            if (isValidXandY(newx, newy, mat, N, M)) {
                mat[newx][newy] = mat[x][y] +1;
                pair temp = {newx, newy};
                Q.enqueue(temp);
            }
        }
    }
    if (mat[newx][newy] == 0) {
        return -1;
    } else {
        return mat[newx][newy];
    }
}

