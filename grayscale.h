#ifndef _gryscale2_h
#define _gryscale2_h
#endif
#include <stdio.h>
#include<time.h>
#include"ppmlib.h"


void changeGray(int n2,int x,int y){
    int col;
    float r, g, b, gl;
    
    r = image[n2][x][y][0];
    g = image[n2][x][y][1];
    b = image[n2][x][y][2];
    
    gl = 0.3*r + 0.59*g + 0.11*b;
    for(col=0;col<3;col++) image[n2][x][y][col]=gl;
}

void paint(int n2,int lowRGB[3],int highRGB[3],int lowRGB2[3],int highRGB2[3],int lowRGB3[3],int highRGB3[3],int lowRGB4[3],int highRGB4[3]){
    
    int x,y,col;
    int colorRGB[3];
    
    
    for(y=0;y<height[n2];y++){
        for(x=0;x<width[n2];x++){
            for(col=0;col<3;col++) {
                colorRGB[col]=image[n2][x][y][col];
            }
            int boolean=0;
            if(colorRGB[0] >= lowRGB[0] && colorRGB[0] <= highRGB[0]){
                if(colorRGB[1] >= lowRGB[1] && colorRGB[1] <= highRGB[1]){
                    if(colorRGB[2] >= lowRGB[2] && colorRGB[2] <= highRGB[2]){
                        boolean=1;
                    }
                }
            }
            if(colorRGB[0] >= lowRGB2[0] && colorRGB[0] <= highRGB2[0]){
                if(colorRGB[1] >= lowRGB2[1] && colorRGB[1] <= highRGB2[1]){
                    if(colorRGB[2] >= lowRGB2[2] && colorRGB[2] <= highRGB2[2]){
                        boolean=1;
                    }
                }
            }
            if(colorRGB[0] >= lowRGB3[0] && colorRGB[0] <= highRGB3[0]){
                if(colorRGB[1] >= lowRGB3[1] && colorRGB[1] <= highRGB3[1]){
                    if(colorRGB[2] >= lowRGB3[2] && colorRGB[2] <= highRGB3[2]){
                        boolean=1;
                    }
                }
            }
            if(colorRGB[0] >= lowRGB4[0] && colorRGB[0] <= highRGB4[0]){
                if(colorRGB[1] >= lowRGB4[1] && colorRGB[1] <= highRGB4[1]){
                    if(colorRGB[2] >= lowRGB4[2] && colorRGB[2] <= highRGB4[2]){
                        boolean=1;
                    }
                }
            }
            
            if(boolean==0)changeGray(n2,x,y);
        }
    }
}