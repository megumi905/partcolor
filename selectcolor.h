#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppmlib.h"
#pragma once

struct color {
    char name[5];
    int num;
};

void sort(struct color x[],int n){ /*カウントした色をソート*/
    int i,j,k;
    struct color temp;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++)
            if(x[j].num > x[k].num) k=j;
        temp=x[i]; x[i]=x[k]; x[k]=temp;
    }
}

void count_color(){            /*色をカウントして多い順に表示*/
    struct color colorName[7];
    int x,y;
    float r,g,b;

    /*7色に設定*/
    strcpy(colorName[0].name,"赤");
    strcpy(colorName[1].name,"緑");
    strcpy(colorName[2].name,"青");
    strcpy(colorName[3].name,"白");
    strcpy(colorName[4].name,"黒");
    strcpy(colorName[5].name,"黄");
    strcpy(colorName[6].name,"紫");
    
    for(y=0;y<height[1];y++){
        for(x=0;x<width[1];x++){
            
            r = image[1][x][y][0];
            g = image[1][x][y][1];
            b = image[1][x][y][2];
            
            if(128<=r && r<=232 && 0<=g && g<=94 && 0<=b && b<=80) {
                colorName[0].num++;//red++;
            } else if((0<=r && r<=15 && 123<=g && g<=174 && 54<=b && b<=129)||(r==0 && 149<=g && g<=171 && 117<=b && b<=129)||(47<=r && r<=71 && 88<=g && g<=136 && 40<=b && b<=96)||(238<=r && r<=255 && 175<=g && g<=192 && 0<=b && b<=1)) {
	      colorName[1].num++; //green++;
	    } else if((r==0 && g==0 && 126<=b && b<=139)||(0<=r && r<=1 && 75<=g && g<=115 && 128<=b && b<=179)||(r==30 && g==0 && b==170)||(r==0 && g==0 && 126<=b && b<=139)){
                colorName[2].num++; //blue++;
            } else if(r==255 && g==255 && b==255) {
                colorName[3].num++; //white++;
            } else if(10<=r && r<=37 && 0<=g && g<=26 && 0<=b && b<=22) {
                colorName[4].num++; //black++;
            } else if((245<=r && r<=255 && 118<=g && g<=242 && 71<=b && b<=118)||(238<=r && r<=255 && 175<=g && g<=230 && 0<=b && b<=14)) {
                colorName[5].num++; //yellow++;
            } else if((55<=r && r<=75 && 5<=g && g<=23 && 60<=b && b<=75)||(103<=r && r<=126 && 69<=g && g<=96 && 140<=b && b<=168)||(134<=r && r<=191 && 64<=g && g<=106 && 136<=b && b<=166)) {
                colorName[6].num++; //purple++;
            }
        }
    }
    sort(colorName,7);
    for(int i=0; i<7; i++) {
      printf("%s",colorName[i].name);
      printf("%d",colorName[i].num);      
      printf("ピクセル\n");
      }
    //printf("\n");
}
