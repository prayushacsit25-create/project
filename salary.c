#include <stdio.h>
#include <grpahics.h>

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
    rectangle (240,240,450,360);

for(i=0;i<4;i++){

if(a[i].balance<1000) {

sprintf (text, "Balance less than 1000;");

outtextxy(250,250,text);

sprintf (text, "Acc_no=%d",a[i].acc_no);

outtextxy(250,270,text);
 
sprintf (text, "Name=%s", a[i].name);

outtextxy(250,290,text);

sprintf (text, "Balance=%.2f",a[i].balance);

outtextxy(250,310,text);

}

}
    
    fclose(fp);
    return 0;
}
