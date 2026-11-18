#include <stdio.h>

int main() {
    int n, i;
    float marks[20], total = 0, highest, lowest, percent;

    printf("Kitne subjects hain: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Galat input!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Subject %d ke marks (out of 100): ", i + 1);
        scanf("%f", &marks[i]);
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Galat marks!\n");
            return 1;
        }
        total += marks[i];
    }

    highest = lowest = marks[0];
    for (i = 1; i < n; i++) {
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];
    }

    percent = total / n;

    printf("\nTotal: %.2f / %d\n", total, n * 100);
    printf("Percentage: %.2f%%\n", percent);
    printf("Sabse zyada marks: %.2f\n", highest);
    printf("Sabse kam marks: %.2f\n", lowest);

    if (percent >= 90) printf("Grade: A+\n");
    else if (percent >= 80) printf("Grade: A\n");
    else if (percent >= 70) printf("Grade: B\n");
    else if (percent >= 60) printf("Grade: C\n");
    else if (percent >= 50) printf("Grade: D\n");
    else printf("Grade: F\n");

    return 0;
}
