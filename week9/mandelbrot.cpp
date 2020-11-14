#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x, y;
    int r;

    char io[4];
    int counter = 1;
    while (cin >> x >> y >> r) {
        double real, img;
        real = img = 0;
        while (r-- && real*real+img*img < 4) {
            int temp = real;
            real = pow(real, 2) - pow(img,2) + x;
            img = 2*temp*img + y; 
            // cout << real << ":" << img << endl;
        }

        if (real*real+img*img >= 4) {
            strcpy(io, "OUT");
        } else {
            strcpy(io, "IN");
        }
        cout << "Case " << counter << ": " << io <<endl;
        counter++;
    }
    return 0;
}