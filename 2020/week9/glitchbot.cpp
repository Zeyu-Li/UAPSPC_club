#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int cases;
    scanf("%d", &cases);

    char options[cases];

    // stdin
    for (int i = 0;i<cases;i++) {
        char buff[9];
        scanf("%s", buff);

        options[i] = buff[0];
    }
    
    int _x, _y;
    _x = _y = 0;
    int current;

    // brute force
    // for all options
    for (int i = 0;i<cases;i++) {
        // for the one not picked
        for (int j = 0;j<3;j++) {
            // skip if corrisplonding letter
            if (j == 0 && options[i] == 'F') {
                continue;
            } else if (j == 1 && options[i] == 'L')
            {
                continue;
            } else if (j == 2 && options[i] == 'R')
            {
                continue;
            }
            
            
            _x = _y = 0;
            // 0 -> up, 1 -> right, 2 -> down etc.
            int state = 0;
            char last_set;
            // preform test and calculate final destination
            for (int k = 0;k<cases;k++) {
                if (i == k) {
                    // preform test 
                    switch (j)
                    {
                    case 0:
                        current = last_set = 'F';
                        break;
                    case 1:
                        current = last_set = 'L';
                        break;
                    case 2:
                        current = last_set = 'R';
                        break;
                    }
                } else {
                    current = options[k];
                }
                if (current == 'F') {
                    switch (state)
                    {
                    case 0:
                        _y++;
                        break;
                    case 1:
                        _x++;
                        break;
                    case 2:
                        _y--;
                        break;
                    case 3:
                        _x--;
                        break;
                    }
                } else if (current == 'R') {
                    state = (state + 1) %4;
                } else {
                    state = (state - 1) %4;
                    if (state < 0) {
                        state+=4;
                    }
                }
            }
        
            if (_x == x && _y == y) {
                if (last_set == 'F') {
                    cout << i + 1 << " Forward" << endl;
                } else if (last_set == 'R')
                {   
                    cout << i + 1 << " Right" << endl;
                } else
                {
                    cout << i + 1 << " Left" << endl;
                }
                
                
                return 0;
            }
        }
    }

    return 0;
}