#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int size = 10;
    // groups
    vector<vector<pair<int,int>>> groups(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char current;
            cin >> current;
            if (current == '\n') {
                cin >> current;
            }
            int group = current - '0';
            groups[group].push_back(make_pair(i,j));
        }
    }

    // stars
    bool stars[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char current;
            cin >> current;
            if (current == '\n') {
                cin >> current;
            }
            if (current == '.') {
                stars[i][j] = false;
            } else {
                stars[i][j] = true;
            }
        }
    }

    // check 2 in row and column
    for (int i = 0; i < 10; i++) {
        int row_c = 0;
        int col_c = 0;
        for (int j = 0; j < 10; j++) {
            if (stars[i][j]) {
                row_c++;
                // check adject
                for (int x = -1; x <= 1; ++x) {
                    if (!(-1 < x+i && x+i <10)) {
                        continue;
                    }
                    for (int y = -1; y <= 1; ++y) {
                        if (!(-1 < y+j && y+j <10)) {
                            continue;
                        }
                        if ((x != 0 || y != 0) && stars[x+i][y+j]) {
                            cout << "invalid\n";
                            return 0;
                        }
                    }
                }
            }
            if (stars[j][i]) {
                col_c++;
            }
        }
        if (row_c != 2 || col_c!=2) {
            cout << "invalid\n";
            return 0;
        }
    }

    // check 2 in group
    for (auto i: groups) {
        int count = 0;
        for (auto j: i) {
            if (stars[j.first][j.second]) {
                count++;
            }
        }
        if (count != 2) {
            cout << "invalid\n";
            return 0;
        }
    }
    cout << "valid\n";
    return 0;
}
