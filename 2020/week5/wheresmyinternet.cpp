
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int houses, cables;

    scanf("%d %d", &houses, &cables);

    int connections[cables][2];

    // scans
    for (int i = 0; i < cables; i++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);

        // insert in decreasing order tuple
        if (temp1 < temp2) {
            connections[i][0] = temp1;
            connections[i][1] = temp2;
        } else {
            connections[i][0] = temp2;
            connections[i][1] = temp1;
        }
    }

    // sorts array via bubble
    for (int j = 0; j < cables; j++) {
        // sinks (bubbles) the largest number to the end
        for (int i = 0; i < cables - 1; i++) {
            if (connections[i][0] > connections[i+1][0]) {
                int temp = connections[i];
                connections[i] = connections[i+1];
                connections[i+1] = temp;
            }
        }
    }

    // init the first 1 house
    int con = 1;
    bool print = false;
    vector<int> connected;
    int connect_line;
    connected.push_back(connections[0][0]);
    connect_line = connections[0][1];
    

    find_next(cables, connections, connected, connect_line);
}

void find_next(int cables, int connections[], vector<int> connected, int connect_line) {
    
    for (int i = 0; i < cables; i++) {
        
        if (connect_line == connections[i][0])  {
            connect_line = connections[i][1];
        } else if (connect_line > connections[i][0]) {
            // if greater than connection line, it is not in the array b/c sorted in increasing order
            break;
        }
    }
}
