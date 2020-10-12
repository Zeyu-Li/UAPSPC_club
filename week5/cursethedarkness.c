#include <stdio.h>

int main() {
    int cases;
    scanf("%d", &cases);

    double book_x, book_y;
    int candles, light;

    while (cases--) {
        light = 0;
        scanf("%lf %lf", &book_x, &book_y);

        scanf("%d", &candles);
        double candles_x, candles_y;
        while (candles--) {
            scanf("%lf %lf", &candles_x, &candles_y);
            double x = book_x - candles_x, y = book_y - candles_y;
            // check radius
            if ((x * x + y * y) <= 64) {
                printf("light a candle\n");
                light = 1;
                while (candles--) scanf("%lf %lf", &candles_x, &candles_y);
                break;
            }
        }
        if (!light) {
            printf("curse the darkness\n");
        }

    }
}