#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
struct account{
    int acc_no;
    char name[20];
    char address[100];
    int balance;
    int time;
};
void main() {
    clrscr();
    struct account a[4];
    FIle *fp;
    int i;
    fp=fopen("bank.txt","r");
    if (fp=NULL)
    {
        printf("Error in opening file");
    }
    else
    {
        printf("Details are:/n);
            for(i=0;i<4,i++)
            {
            fscanf(fp,"%d %s %s %d %d",&a[i].acc_no,a[i].name,a[i].address);
            printf("%d/t %s/t %s/t %d/t %d/t",&a[i].acc_no,a[i].name,a[i].address);
            }
        }
            // active accounts
            int activecount=0;
            rectangle(460,240,630,360);gi
            for(i=0;i<4;i++);
            {
            if (a[i].time<12)
            {
            activecount++;
            }
            }
            sprintf(text,"Total =%d",activecount);
            outtextxy(470,270,text);
            fclose(fp);
            getch();
        }
