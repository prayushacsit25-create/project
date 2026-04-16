#include <stdio.h>

struct Bank {
    int acc_no;
    char name[50];
    char address[50];
    float balance;
};

int main() {
    FILE *fp;
    struct Bank b, max, min;
    int n, i;

    fp = fopen("bank.txt", "r");  // read from file

    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("Enter number of accounts: ");
    scanf("%d", &n);

    // Read first record
    fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance);
    max = min = b;

    // Loop through remaining
    for (i = 1; i < n; i++) {
        fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance);

        if (b.balance > max.balance) {
            max = b;
        }

        if (b.balance < min.balance) {
            min = b;
        }
    }

    printf("\nHighest Balance Account:\n");
    printf("Acc No: %d\nName: %s\nBalance: %.2f\n",
           max.acc_no, max.name, max.balance);

    printf("\nLowest Balance Account:\n");
    printf("Acc No: %d\nName: %s\nBalance: %.2f\n",
           min.acc_no, min.name, min.balance);

    fclose(fp);

    return 0;
}