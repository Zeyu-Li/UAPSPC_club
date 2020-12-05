#include <cstdio>
#include <cmath>

using namespace std;


int main(){
    int cases;
    scanf("%d", &cases);

    int four = 4;

    char operators[5] = "+-*/";

    while (cases--) {
        int num;
        scanf("%d", &num);
        if (num > 256 || num < -60) {
            printf("no solution\n");
        } else {
            // iterate through all cases
            for (int i = 0; i < four; i++) {
                for (int j = 0; j < four; j++)  {
                    for (int k = 0; k < four; k++)  {
                        for (int l = 0; l < four; l++)  {
                            ;
                        }
                    }
                }
            }
        }
    }

    return 0;
}