#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

struct account {
    int acc_no;
    char name[20];
    char address[100];
    int balance;
    int time;
};

void main() {
    struct account a[4];
    FILE *fp;
    int i;
    int activecount = 0;
    char text[50]; 
    int gd = DETECT, gm;

    
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); 

    fp = fopen("bank.txt", "r");
    if (fp == NULL) { 
        printf("Error in opening file");
    } else {
        printf("Details are:\n");
        for (i = 0; i < 4; i++) { 
            fscanf(fp, "%d %s %s %d %d", &a[i].acc_no, a[i].name, a[i].address, &a[i].balance, &a[i].time);
            
            printf("%d\t %s\t %s\t %d\t %d\n", a[i].acc_no, a[i].name, a[i].address, a[i].balance, a[i].time);
        }
        fclose(fp);
    }

    
    rectangle(460, 240, 630, 360);
    for (i = 0; i < 4; i++) { 
        if (a[i].time < 12) {
            activecount++;
        }
    }

    sprintf(text, "Total Active = %d", activecount);
    outtextxy(470, 270, text);
    fclose(fp);
    getch();
}
