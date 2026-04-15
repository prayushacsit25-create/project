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

    fp=fopen("bank.txt", "w");

    if (fp==NULL) {
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

    fp=fopen("bank.txt", "r");

    if (fp==NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Read first record
    if (fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance) != EOF) {
        max=min=b;
    }

    // Compare remaining records
    while (fscanf(fp, "%d %s %s %f", &b.acc_no, b.name, b.address, &b.balance) != EOF) {

        if (b.balance > max.balance) {
            max=b;
        }

        if (b.balance < min.balance) {
            min=b;
        }
    }

    fclose(fp);

    printf("\nHighest Balance Account\n");
    printf("Acc No: %d\nName: %s\nAddress: %s\nBalance: %.2f\n",
           max.acc_no, max.name, max.address, max.balance);

    printf("\nLowest Balance Account\n");
    printf("Acc No: %d\nName: %s\nAddress: %s\nBalance: %.2f\n",
           min.acc_no, min.name, min.address, min.balance);

    return 0;
}