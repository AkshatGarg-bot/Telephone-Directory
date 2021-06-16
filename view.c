#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"print2Dgroup.h"

void view()
{
  system("clear");
  printf("✰✰✰✰✰ e-Telephone Directory ✰✰✰✰✰\n\n");
  system("sort -o data_base.txt data_base.txt");
  FILE* fp=fopen("data_base.txt","a+");
  char single_contact[2000], details[7][175];
  int row, column, i, j, serial=1;
  while(fgets(single_contact,1999,fp))//picking up each line of the file.
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)//making a 2D array out of it.
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    print2Dgroup(details,serial); //printing 2d array in fancy mannner.
    serial++;
    for(i=0;i<7;i++)//Nullifying the 2d array for furthur use.
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
}

