#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Piece {
    public:
    int id;
    int direction;

    Piece(int id, int direction) {
        this->id = id;
        this->direction = direction;
    }
};

class Dummy {
    public:
        int x;
        int y;
        Piece* bottom_piece;
        Piece* top_piece;
        int num;
        bool usable;

        Dummy(int x, int y, Piece* piece) {
            this->x = x;
            this->y = y;
            this->bottom_piece = piece;
            this->top_piece = piece;
            this->num = 1;
            this->usable = true;
        }
};

int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int counter_direction[4] = {1, 0, 3, 2};
int N, K;
int map_color[12][12];
Dummy* dummies[10];
Piece* pieces[10];

int find_dummy_id(int piece_id) {
    for (int i = 0; i < K; i++) {
        if (dummies[i]->usable && dummies[i]->bottom_piece->id == piece_id) return i;
    }

    return -1;
}

int find_dummy(int x, int y) {
    for (int i = 0; i < K; i++)
    {
        if (dummies[i]->usable && dummies[i]->x == x && dummies[i]->y == y)
            return i;
    }

    return -1;
}

bool play_turn() {
    for (int i = 0; i < K; i++) {
        int dummy_id = find_dummy_id(i);
        if (dummy_id == -1) continue;
        Dummy *dummy = dummies[dummy_id];
        Piece *piece = pieces[i];

        int dir = piece->direction;
        int next_x = dummy->x + direction[dir][0];
        int next_y = dummy->y + direction[dir][1];
        
        bool retry = false;
        while (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || map_color[next_x][next_y] == 2) {
            dir = counter_direction[dir];
            piece->direction = dir;
            if (retry) {
                next_x = dummy->x;
                next_y = dummy->y;
                break;
            }
            next_x = dummy->x + direction[dir][0];
            next_y = dummy->y + direction[dir][1];
            retry = true;
        }        

        if (next_x != dummy->x || next_y != dummy->y) {
            if (map_color[next_x][next_y] == 1)
            {
                Piece *bottom_piece = dummy->bottom_piece;
                dummy->bottom_piece = dummy->top_piece;
                dummy->top_piece = bottom_piece;
            }
            int next_dummy_id = find_dummy(next_x, next_y);
            dummy->x = next_x;
            dummy->y = next_y;
            
            if (next_dummy_id != -1)
            {
                Dummy* next_dummy = dummies[next_dummy_id];
                next_dummy->usable = false;
                // piece->direction = dir;
                dummy->bottom_piece = next_dummy->bottom_piece;
                dummy->num += next_dummy->num;
            }
        }
        for (int j = 0; j < K; j++) {
        }

        if (dummy->num >= 4) return true;
    }
    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map_color[i][j];
        }
    }
    
    for (int i = 0; i < K; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        pieces[i] = new Piece(i, dir-1);
        dummies[i] = new Dummy(x-1, y-1, pieces[i]);
    }

    int turn = 0;
    while (true) {
        turn++;
        if (play_turn()) break;
        if (turn >= 1000) {
            turn = -1;
            break;
        }
    }
    cout << turn << endl;
}