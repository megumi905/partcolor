/*mainp.c*/
#include<stdio.h>
#include"selectcolor.h"
#include"grayscale.h"
#include"ppmlib.h"

#define MAX_COLORNAME 256 /*入力する色の名前*/
int main() {
  load_color_image(0,"");
  copy_color_image(0,1);
 
  char cname[MAX_COLORNAME];
  count_color();
  printf("この中から残したい色を入力してください。\n");
  scanf("%s",cname);/*残す色をユーザが入力*/

  int lowRGB[3];
  int highRGB[3];
    int lowRGB2[3];
    int highRGB2[3];
    int lowRGB3[3];
    int highRGB3[3];
    int lowRGB4[3];
    int highRGB4[3];
    
  if(strcmp(cname,"赤")==0){
    lowRGB[0]=128;lowRGB[1]=0;lowRGB[2]=0;
    highRGB[0]=232;highRGB[1]=94;highRGB[2]=80;
  } else if(strcmp(cname,"緑")==0) {
    lowRGB[0]=0;lowRGB[1]=123;lowRGB[2]=154;
    highRGB[0]=15;highRGB[1]=174;highRGB[2]=129;
    lowRGB2[0]=0;lowRGB2[1]=149;lowRGB2[2]=117;
    highRGB2[0]=47;highRGB2[1]=171;highRGB2[2]=129;
    lowRGB3[0]=71;lowRGB3[1]=88;lowRGB3[2]=40;
    highRGB3[0]=15;highRGB3[1]=136;highRGB3[2]=96;
    lowRGB4[0]=238;lowRGB4[1]=175;lowRGB4[2]=0;
    highRGB4[0]=255;highRGB4[1]=192;highRGB4[2]=1;
  } else if(strcmp(cname,"青")==0) {
    lowRGB[0]=0;lowRGB[1]=0;lowRGB[2]=126;
    highRGB[0]=0;highRGB[1]=0;highRGB[2]=139;
    lowRGB2[0]=0;lowRGB2[1]=75;lowRGB2[2]=128;
    highRGB2[0]=1;highRGB2[1]=115;highRGB2[2]=179;
    lowRGB3[0]=30;lowRGB3[1]=0;lowRGB3[2]=170;
    highRGB3[0]=30;highRGB3[1]=0;highRGB3[2]=170;
    lowRGB4[0]=0;lowRGB4[1]=0;lowRGB4[2]=126;
    highRGB4[0]=0;highRGB4[1]=0;highRGB4[2]=139;
  } else if(strcmp(cname,"白")==0) {
    lowRGB[0]=255;lowRGB[1]=255;lowRGB[2]=255;
    highRGB[0]=255;highRGB[1]=255;highRGB[2]=255;
  } else if(strcmp(cname,"黒")==0) {
    lowRGB[0]=0;lowRGB[1]=0;lowRGB[2]=0;
    highRGB[0]=37;highRGB[1]=29;highRGB[2]=22;
  } else if(strcmp(cname,"黄")==0) {
    lowRGB[0]=245;lowRGB[1]=118;lowRGB[2]=71;
    highRGB[0]=255;highRGB[1]=242;highRGB[2]=118;
    lowRGB2[0]=238;lowRGB2[1]=175;lowRGB2[2]=0;
    highRGB2[0]=255;highRGB2[1]=230;highRGB2[2]=14;
  } else if(strcmp(cname,"紫")==0) {
    lowRGB[0]=55;lowRGB[1]=5;lowRGB[2]=60;
    highRGB[0]=75;highRGB[1]=23;highRGB[2]=75;
    lowRGB2[0]=103;lowRGB2[1]=69;lowRGB2[2]=140;
    highRGB2[0]=126;highRGB2[1]=96;highRGB2[2]=168;
    lowRGB3[0]=134;lowRGB3[1]=64;lowRGB3[2]=136;
    highRGB3[0]=191;highRGB3[1]=106;highRGB3[2]=166;
  } else {
    printf("入力が正しくありません。"); exit(0);
  }
  paint(1,lowRGB,highRGB,lowRGB2,highRGB2,lowRGB3,highRGB3,lowRGB4,highRGB4);
  save_color_image(1,"");
  return 0;
}
