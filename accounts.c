#include<stdio.h>
struct bank{
    int acc_no;
    char name[20];
    char address[50];
    float balance;
};
void main(){
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    struct bank b[n];
    int i;
    FILE *fp;
    fp=fopen("record.txt","w");
    for(i=0;i<n;i++){
        printf("Enter details of %d person",i+1);
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
