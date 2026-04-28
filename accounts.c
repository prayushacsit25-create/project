#include<stdio.h>
struct account{
    int acc_no;
    char name[20];
    char address[20];
    int balance;
    int time;
};
void main(){
    struct bank a[4];
    int i;
    FILE *fp;
    fp=fopen("bank.txt","w");
    printf("Enter details of 4 customers:")
    for(i=0;i<4;i++){
        printf("Enter details of %d person",i+1);
        printf("\nAccount number=");
        scanf("%d",&a[i].acc_no);
         printf("\nName=");
        scanf("%s",a[i].name);
         printf("\nAddress=");
        scanf("%s",a[i].address);
         printf("\nBalance=");
        scanf("%d",&a[i].balance);
        printf("\nRecent transaction month:");
        scanf("%d",&a[i].time);
        fprintf(fp,"%d %s %s %d %d\n",a[i].acc_no,a[i].name,a[i].address,a[i].balance,a[i].time);
    }
    printf("Successful");
    fclose(fp);

}


