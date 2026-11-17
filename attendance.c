#include <stdio.h>

int main() {
    int total, attended;
    float percent;
    int required = 75;   // college ka rule, zarurat ho to badal lo

    printf("Ab tak total classes: ");
    scanf("%d", &total);
    printf("Aapne kitni attend ki: ");
    scanf("%d", &attended);

    if (total <= 0 || attended < 0 || attended > total) {
        printf("Galat input!\n");
        return 1;
    }

    percent = (attended * 100.0) / total;
    printf("Aapki attendance: %.2f%%\n", percent);

    if (percent >= required) {
        int canMiss = 0;
        while ((attended * 100.0) / (total + canMiss + 1) >= required)
            canMiss++;
        printf("Safe hai! Aap aur %d classes miss kar sakte ho.\n", canMiss);
    } else {
        int need = 0;
        while (((attended + need) * 100.0) / (total + need) < required)
            need++;
        printf("Dhyan do! %d classes lagatar attend karni hongi.\n", need);
    }

    return 0;
}
