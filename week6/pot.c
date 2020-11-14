#include <math.h>
#include <stdio.h>

int main(){
    int input;
    int total = 0;
    while (scanf("%i", &input) == 1) {
        // solve test case and output answer
        total += pow(input / 10, input % 10); 
    }

    printf("%i\n", total);
    return 0;
}
