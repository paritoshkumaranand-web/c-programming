#include <stdio.h>

#define MAX 10

struct Subject {
    char name[30];
    int daysLeft;
    int difficulty;
    float weight;
    float hours;
};

void printPlan(FILE *out, struct Subject s[], int n, float total) {
    int i;
    fprintf(out, "\n%-20s %-10s %-12s %-10s\n", "Subject", "Din bache", "Difficulty", "Ghante");
    fprintf(out, "--------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        fprintf(out, "%-20s %-10d %-12d %-10.1f\n",
                s[i].name, s[i].daysLeft, s[i].difficulty, s[i].hours);
    }
    fprintf(out, "--------------------------------------------------------\n");
    fprintf(out, "Aaj ka total padhai time: %.1f ghante\n", total);
}

int main() {
    struct Subject s[MAX], temp;
    int n, i, j;
    float hoursPerDay, sumWeight = 0;
    FILE *fp;

    printf("Kitne subjects hain (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Galat input!\n");
        return 1;
    }

    printf("Aaj kitne ghante padh sakte ho: ");
    scanf("%f", &hoursPerDay);
    if (hoursPerDay <= 0 || hoursPerDay > 16) {
        printf("Galat input!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nSubject %d ka naam: ", i + 1);
        scanf(" %29[^\n]", s[i].name);

        printf("Exam me kitne din bache (kam se kam 1): ");
        scanf("%d", &s[i].daysLeft);

        printf("Difficulty (1 = easy, 5 = bahut hard): ");
        scanf("%d", &s[i].difficulty);

        if (s[i].daysLeft < 1 || s[i].difficulty < 1 || s[i].difficulty > 5) {
            printf("Galat input!\n");
            return 1;
        }

        s[i].weight = (float)s[i].difficulty / s[i].daysLeft;
        sumWeight += s[i].weight;
    }

    /* Bubble sort: jis exam me din kam bache, wo upar */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (s[j].daysLeft > s[j + 1].daysLeft ||
                (s[j].daysLeft == s[j + 1].daysLeft &&
                 s[j].difficulty < s[j + 1].difficulty)) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        s[i].hours = hoursPerDay * s[i].weight / sumWeight;

    printPlan(stdout, s, n, hoursPerDay);

    fp = fopen("study_plan.txt", "w");
    if (fp != NULL) {
        printPlan(fp, s, n, hoursPerDay);
        fclose(fp);
        printf("\nPlan 'study_plan.txt' me save ho gaya.\n");
    } else {
        printf("\nFile save nahi ho payi.\n");
    }

    return 0;
}
