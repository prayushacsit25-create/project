#include <stdio.h>

struct Bank {
    int acc_no;
    char name[50];
    char address[50];
    float balance;
    int is_active;
};

int main() {
    FILE *fp;
    struct Bank b, max, min;
    int n, i;

    // ===== INPUT =====
    fp = fopen("bank.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("Enter number of accounts: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of account %d:\n", i + 1);
        printf("Account No: ");
        scanf("%d", &b.acc_no);
        printf("Name: ");
        scanf("%s", b.name);
        printf("Address: ");
        scanf("%s", b.address);
        printf("Balance: ");
        scanf("%f", &b.balance);
        fprintf(fp, "%d %s %s %.2f\n", b.acc_no, b.name, b.address, b.balance);
    }
    fclose(fp);

    // ===== PART 1: Highest & Lowest Balance (Friend 1) =====
    fp = fopen("bank.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    if (fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance) != EOF) {
        max = min = b;
    }

    while (fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance) != EOF) {
        if (b.balance > max.balance) max = b;
        if (b.balance < min.balance) min = b;
    }
    fclose(fp);

    printf("\n===== Highest Balance Account =====\n");
    printf("Acc No: %d\nName: %s\nAddress: %s\nBalance: %.2f\n",
           max.acc_no, max.name, max.address, max.balance);

    printf("\n===== Lowest Balance Account =====\n");
    printf("Acc No: %d\nName: %s\nAddress: %s\nBalance: %.2f\n",
           min.acc_no, min.name, min.address, min.balance);

    // ===== PART 2: Display Customers from Kathmandu (Friend 2) =====
    fp = fopen("bank.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("\n===== Customers from Kathmandu =====\n");
    int found = 0;
    while (fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance) != EOF) {
        if (strcmp(b.address, "Kathmandu") == 0) {
            printf("Acc No: %d\nName: %s\nAddress: %s\nBalance: %.2f\n",
                   b.acc_no, b.name, b.address, b.balance);
            found = 1;
        }
    }
    if (!found) printf("No customers from Kathmandu found.\n");
    fclose(fp);

    // ===== PART 3: Accounts with Balance < 1000 (Your Part) =====
    fp = fopen("bank.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("\n===== Accounts with Balance less than 1000 =====\n");
    int count = 0;
    while (fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance) != EOF) {
        if (b.balance < 1000) {
            printf("Acc No: %d\nName: %s\nAddress: %s\nBalance: %.2f\n",
                   b.acc_no, b.name, b.address, b.balance);
            count++;
        }
    }
    if (count == 0) printf("No accounts with balance less than 1000.\n");
    fclose(fp);

    return 0;
}
