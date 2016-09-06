#include<iostream>
using namespace std;
bool canRatEatCheese(int maze[][100], int N, int M, int x, int y, int fx, int fy) {
    if (x == fx && y == fy) {
        return true;
    }
    int delta[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (int i = 0; i < 4; i++) {
        int newx = x + delta[i][0];
        int newy = y + delta[i][1];
        if ( newx >= 0 && newx < N && newy >=0 && newy < M && maze[newx][newy] == 0) {
            maze[newx][newy] = 2;
            int ans = canRatEatCheese(maze, N, M, newx, newy, fx, fy);
            if (ans == true) {
                return true;
            } else {
                maze[newx][newy] = 1;
            }
        }
    }
    return false;
}
int main() {
    int maze[100][100];
    int N, M, startx, starty, finalx, finaly;
    cout << " Enter Maze Size" << endl;
    cin >> N >> M;
    cout << " Enter Maze " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    cout << " Enter co-ordinate for RAT ";
    cin >> startx >> starty;
    cout << " Enter co ordinate for CHEESE ";
    cin >> finalx >> finaly;
    maze[startx][starty] = 2;
    int ans = canRatEatCheese(maze, N, M, startx, starty, finalx, finaly);
    cout << ans << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}

