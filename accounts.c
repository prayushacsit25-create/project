#include<stdio.h>
struct bank{
    int acc_no;
    char name[20];
    char address[50];
    float balance;
};
void main(){
    struct bank b[5];
    int i;
    FILE *fp;
    fp=fopen("bank.txt","w");
    printf("Success\n");
    for(i=0;i<5;i++){
        printf("Enter details of %d student",i+1);
        printf("\nAccount number=");
        scanf("%d",&b[i].acc_no);
         printf("\nName=");
        scanf("%s",b[i].name);
         printf("\nAddress=");
        scanf("%s",b[i].address);
         printf("\nBalance=");
        scanf("%f",&b[i].balance);
        fprintf(fp,"%d %s %s %f\n",b[i].acc_no,b[i].name,b[i].address,b[i].balance);
    }
    printf("Successful");
    fclose(fp);
}