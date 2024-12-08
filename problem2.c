#include <stdio.h>

int generateSeries(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return generateSeries(n - 1) + generateSeries(n - 2) + generateSeries(n - 3);
}

int main() {
    int n;
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &n);

    printf("Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", generateSeries(i));
    }
    printf("\n");

    return 0;
}
