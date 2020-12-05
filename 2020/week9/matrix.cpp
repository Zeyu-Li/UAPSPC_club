#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int matrix[2][2];

    auto count = 1;
    while (cin >> matrix[0][0] >> matrix[0][1] >> matrix[1][0] >> matrix[1][1]) {
        cout << "Case " << count << ':'<<endl;
        int det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        cout<< matrix[1][1]/det << " "<< -matrix[0][1]/det<<endl<<-matrix[1][0]/det<< ' '<< matrix[0][0]/det<<endl;
        count++;
    }

    return 0;
}