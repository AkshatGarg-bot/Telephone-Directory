//USING THE DELETE FUNCTION TO DELETE THE CONTENTS OF THE CONTACT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"string_compare.h"
#include"print2D.h"    
  
void new_file(char name[]) //CONTAINS THE DELETE FUNCTION AND STORING THE ELEMENTS INTO A NEW FILE AND THEN RENAMING IT
{
  char single_contact[2000], details[7][175];
  int check=0, i, j, row, column;
  FILE* fp=fopen("data_base.txt","a+");	
  FILE* temp=fopen("temp.txt","a+");
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
    if(string_compare(name,details[0])==1)
      fputs(single_contact,temp);
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  remove("data_base.txt");
  rename("temp.txt","data_base.txt");
  fclose(fp);
}  
   
void print_delete(char name[]) //PRINTING THE CONTACT WHICH USER WANT TO DELETE AND CONFORMING WHETHER HE REALLY WANT TO DELETE
{
  char single_contact[2000], details[7][175];
  int check=0, i, j, row, column;
  FILE *fp=fopen("data_base.txt","a+");	
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
    if(string_compare(name,details[0])==0)
      print2D(details);
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  fclose(fp);
}

int checking(char name[50]) //HERE THE WHOLE CHECKING GOES
{ 
  char single_contact[2000], details[7][175];
  int ask, check=0, i, j, row, column;
  FILE *fp=fopen("data_base.txt","a+");	
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
    if(string_compare(name,details[0])==0)
      check++;
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  fclose(fp);
  return check;
}
    
void delete_contact(void)
{ 
  //DECLARING THE VARIABLES LIKE ASK TO ASK USER IF HE REALLY WANT TO DELETE THE CONTACTS 
  char name[50], single_contact[2000], details[7][175];
  printf("Enter the full name of the person whose contact you want to DELETE: ");
  scanf("%s",name);
  int ask, i, j, row, column, check=checking(name);
  FILE *fp=fopen("data_base.txt","a+");	
  if(check==0)
    printf("✦✦✦✦✦ Contact NOT Found ✦✦✦✦✦\n");
  else
  {
    print_delete(name);
    printf("Do you really want to DELETE the above contact(s)?\nEnter 1 for YES.\nEnter any other number for NO.\n");
    scanf("%d",&ask);
    if(ask==1)
    {
      new_file(name);
      printf("✦✦✦✦✦ Contact(s) Deleted Successfully ✦✦✦✦✦\n\n");
    }
    else
      printf("✦✦✦✦✦ Contact NOT deleted ✦✦✦✦✦");
  }
}
