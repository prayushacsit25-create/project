#include <stdio.h>

struct account {
    int acc_no;
    char name[50];
    char address[50];
    float balance;
    int time;
};

int main() {
    FILE *fp;
    struct account a[4];
    int i;

    fp = fopen("record.txt", "r");  // read from file

    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }
     else{
        printf("Details are :\n");
        for (i = 0; i < 4; i++) {
            fscanf(fp, "%d %s %s %f %d", &a[i].acc_no, a[i].name, a[i].address, &a[i].balance, &a[i].time);
            printf("%d\t%s\t%s\t%.2f\t%d\n", a[i].acc_no, a[i].name, a[i].address, a[i].balance, a[i].time);
        }
    }
    int high_balance=a[0].balance;
    int low_balance=a[0].balance;
    int high_index=0,low_index=0;
    for(i=1;i<4;i++){
        if(a[i].balance>high_balance){
            high_balance=a[i].balance;
            high_index=i;
        }
        if(a[i].balance<low_balance){
            low_balance=a[i].balance;
            low_index=i;
        }
    }
    printf("\nHighest balance is : %.2f\n",high_balance);
    printf("Lowest balance is : %.2f\n",low_balance);

    fclose(fp);
    return 0;
}
