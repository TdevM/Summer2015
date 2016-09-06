#include "StacksAsArray.h"
#include<iostream>
using namespace std;
struct data {
    int x;
    int y;
    int direction;
    data() {}
    data(int dx, int dy) : x(dx), y(dy), direction(0) {}
    data(int dx, int dy, int d): x(dx), y(dy), direction(d) {}
};
bool isValidXandY(int x, int y, int mat[][5], int N, int M) {
    if (x < 0 || x>= N || y < 0 || y >= M || mat[x][y] != 0) {
        return false;
    }
    return true;
}
data getNextValidXandY(data & current, int mat[][5], int N, int M) {
    switch(current.direction) {
        case 0: if(isValidXandY(current.x, current.y+1, mat, N, M)) {
                    current.direction = 1;
                    return data(current.x, current.y + 1);
                }
        case 1: if (isValidXandY(current.x+1, current.y, mat, N, M)) {
                    current.direction = 2;
                    return data(current.x+1, current.y);
                }
        case 2: if (isValidXandY(current.x-1, current.y, mat, N, M)) {
                    current.direction = 3;
                    return data(current.x-1, current.y);
                }
        case 3: if (isValidXandY(current.x, current.y-1, mat, N, M)) {
                    current.direction = 4;
                    return data(current.x, current.y-1);
                }
    }
    return data(-1, -1);
}
bool solveRatInAMaze(int startx, int starty, int endx, int endy, int mat[][5], int N, int M) {
    Stack<data> S;
    data init(startx, starty);
    mat[startx][starty] = 2;
    S.push(init);
    while (!S.isEmpty()) {
        data & current = S.getTop();
        if (current.x == endx && current.y == endy) {
            while (!S.isEmpty()) {
                cout << S.getTop().x << " , " << S.getTop().y << endl;
                S.pop();
            }
            return true;
        }
        if (current.direction == 4) {
            S.pop();
            continue;
        }
        data next = getNextValidXandY(current, mat, N, M);
        if (next.x == -1) {
            S.pop();
            continue;
        }
        mat[next.x][next.y] = 2;
        S.push(next);
    }
    return false;
}
int main() {
    int mat[][5] = {
        {0, 0,0,0,0},
        {0, 1,1,1,0},
        {0,1,0,1,0},
        {0,0,0,1,0},
        {0,1,1,1,0},
        {0,1,0,1,0}
    };
    cout << solveRatInAMaze(5,0, 5,2,mat, 6,5) << endl;
    return 0;
}
