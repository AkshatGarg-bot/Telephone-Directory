#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"partial_compare.h"
#include"print2D.h"

void search(void)
{
  system("clear");
  FILE* fp=fopen("data_base.txt","a+"); //opening the file pointer.
  char single_contact[2000], search_material[50];
  char details[7][175];
  int search_choice, row, column, i, j, check=0;
  printf("Please select the appropriate option to search through in the Directory\n"); //menu choice
  printf("Enter\n");
  printf("1 for searching through NAME\n");
  printf("2 for searching through PHONE NUMBER\n");
  printf("3 for searching through EMAIL ADDRESS\n");
  printf("4 for searching through OCCUPATION\n");
  printf("5 for searching through DATE OF BIRTH\n");
  scanf("%d",&search_choice);
  system("clear");
  switch(search_choice)
  {
    case 1: printf("Please enter the name to be searched in the directory\n");
            scanf("%s",search_material);
            search_material[strlen(search_material)]='\0';
            break;
  
    case 2: printf("Please enter the phone number to be searched in the directory\n");
            scanf("%s",search_material); 
            search_material[10]='\0';
            break;

    case 3: printf("Please enter the email address to be searched in the directory\n");
            scanf("%s",search_material);
            break;
    
    case 4: printf("Please enter the occupation to be searched in the directory\n");
            scanf("%s",search_material);
            break;

    case 5: printf("Please enter the date of birth in dd/mm/yyyy format to be searched in the directory\n");
            scanf("%s",search_material);
            break;
    
    default: printf("You are requested to make a valid input choice.");
             break;
  }
  system("clear");
  if(search_choice==1 ||search_choice==2 || search_choice==3 || search_choice==4 || search_choice==5)
    printf("Search Results are as follows: \n\n");
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
    switch(search_choice)
    {
      case 1: details[0][strlen(details[0])]='\0';
              details[1][10]='\0';
              if(partial_compare(search_material,details[0])==0) //comparing the entered name with name in directory.
              {
                print2D(details);
                check=1;
              }
              break;
 
      case 2: details[1][10]='\0';
              //comparing entered phone number with phone numbers in directory.
              if(partial_compare(search_material,details[1])==0 || partial_compare(search_material,details[2])==0)
              {
                print2D(details);
                check=1;
              }
              break;
 
      case 3: if(partial_compare(search_material,details[3])==0) //comparing the emails
              {
                print2D(details);
                check=1; 
              }
              break;
 
      case 4: if(partial_compare(search_material,details[5])==0) //comparing the occupations
              {
                print2D(details);
                check=1; 
              }
              break;

      case 5: details[6][10]='\0';
              if(partial_compare(search_material,details[6])==0) //comparing the date of birth
              {
                print2D(details);
                check=1; 
              }
              break;
    }
    for(i=0;i<7;i++) //Nullifying the 2d array details for furthur use.
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  if(check==0 && (search_choice==1 || search_choice==2 || search_choice==3 || search_choice==4 || search_choice==5))
    printf("NO Match found\n");
  fclose(fp);
}  
