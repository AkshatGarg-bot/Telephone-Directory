#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"print2D.h"
#include"string_compare.h"

int merge(char input[])
{
  char single_contact[2000], details[7][175];
  int i, j, row, column;
  FILE* fp=fopen("data_base.txt","r");
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
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
    if(string_compare(input,details[1])==0 || string_compare(input,details[2])==0 || string_compare(input,details[3])==0)
    {
      fclose(fp);
      return 1;
    }
    for(i=0;i<7;i++) //loop for nullifying details for furthur use.
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  return 0;
}

void similar(char input[]) //function for printing the details if the contact already exists.
{
  FILE* fp=fopen("data_base.txt","r");
  char single_contact[2000];
  char details[7][175];
  int row, column, i, j;
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
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
    details[1][10]='\0';
    details[2][10]='\0';
    if(string_compare(details[1],input)==0 || string_compare(details[2],input)==0 || string_compare(details[3],input)==0)
    {
      print2D(details);
      break;
    }
    for(i=0;i<7;i++) //loop for nullifying details for furthur use.
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  fclose(fp);
}

void add_remove(char input[]) //function that removes the data if it got added.
{
  FILE* fp=fopen("data_base.txt","r");
  FILE* fpt=fopen("temp.txt","a+");
  char single_contact[2000], details[7][175];
  int i, j, row, column, count=0;
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
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
    if(count!=2 && (string_compare(details[1],input)==0 || string_compare(details[2],input)==0) || string_compare(details[3],input)==0)
    {
      count++;
      fputs(single_contact,fpt);
      goto label;
    }
    else if(count!=2)
    {
      fputs(single_contact,fpt);
      goto label;
    }
    label: for(i=0;i<7;i++) //loop for nullifying details for furthur use.
           {
             for(j=0;j<175;j++)
             details[i][j]='\0';
           }
  }
  remove("data_base.txt");
  rename("temp.txt","data_base.txt");
}
