#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class T {
    int _x, _y;
    int honey;
    vector<vector<int>>matrix;
    public:
        void set();
        void cal();
        int fill(int, int);
        void debug();
};

int main(){

    T s;

    s.set();
    s.cal();
    // s.debug();

    // s.cal();

    return 0;
}

void T::cal() {
    vector<int> filled;

    for (int j = 0; j<_y;j++) {
        for (int i = 0; i<_x;i++) {
            int tmp = fill(i,j);
            if (tmp != 0) {
                filled.push_back(tmp);
            }
        }
        // debug();
        // cout << endl;
    }
    sort(filled.begin(), filled.end());
    int num = 0;
    int current = honey;
    for (auto i : filled) {
        current-=i;
        if (current < 0) {
            break;
        }
        num++;
    }
    cout << num << endl;

}

void T::set() {
    cin >> honey >> _y >> _x;

    for (int i = 0; i<_y;i++) {
        vector<int> tmp1;
        for (int j = 0; j<_x;j++) {
            char tmp2;
            cin >> tmp2;
            if (tmp2 == '.') {
                tmp1.push_back(0);
            } else {
                tmp1.push_back(1);
            }
        }
        matrix.push_back(tmp1);
    }
}

int T::fill(int x, int y) {
    // out of bounds
    if (x < 0 || y < 0 || x >= _x || y >= _y) {
        return 0;
    }
    // itself is already filled
    if (matrix[y][x] == 1) {
        return 0;
    }

    int count = 1;
    // fill current
    matrix[y][x] = 1;
    // top and bottom
    int s,b;
	if (y % 2) {
		s = 0;
		b = 2;
    } else {
        s = -1;
        b = 1;
    }
    if (x==3 && y == 3){
        int h = 0;
    }
    for (int j : {-1,1}) {
        for (int i = s; i<b;i++) {
            count += fill(x+i, y+j);
        }
    }

    // fill front and back
    for (int i : {-1,1})
        count += fill(x + i, y);
        
    return count;
}

void T::debug() {
    // debug
    for (int i = 0; i<_y;i++) {
        for (int j = 0; j<_x;j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}