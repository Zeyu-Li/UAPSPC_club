#include <cstdio>
#include <cmath>

using namespace std;


int main(){
    int cases;
    scanf("%d", &cases);

    int four = 4;

    while (cases--) {
        int num;
        scanf("%d", &num);
        if (num > 256 || num < -60) {
            printf("no solution\n");
        }
    }

    return 0;
}