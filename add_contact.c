//MAKING THE ADD FUNCTION SO THAT USER CAN ENTER THE DATA
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"merge_contact.h"
//DELARING THE ARRAY IN STRUCTS ACCORDING TO THE REQUIREMENT OF THE SIZE
struct data_base
{
  char name[50];	
  char phone1[11];
  char phone2[11];
  char email[50];
  char address[175];
  char occupation[20];
  char dob[11];
};

void add_contact(void)
{
  system("clear");
  FILE* fp=fopen("data_base.txt","a+");
  int preference, n, check=0; //CHECK VARIABLE TO CHECK THE CONDITIONS
  printf("Enter the number of contact you wish to add in the Directory : "); //ENTERING THE NUMBER OF CONTACTS YOU WANT TO ADD
  scanf("%d",&n);
  printf("\nNOTE :\n1)Enter '-' if you do not wish to enter that particular type of information into the Directory.\n");
  printf("2)Strings of name, occupation and address need to be separated by '-'\n");
  struct data_base info;
  while(n>0)	
  {
    printf("\nEnter full name : ");
    scanf("%s",info.name);
    fputs(info.name,fp);
    fprintf(fp,"\t");
    printf("Enter the 1st phone number : ");
    scanf("%s",info.phone1);                
    if(merge(info.phone1)==1)         
    { 
      system("clear");
      check=1;                                      
      printf("This telephone number already exists in the Directory.\n");
      printf("\nThe following are the details of that contact: \n\n");
      similar(info.phone1);
      fputs(info.phone1,fp);
      fprintf(fp,"\t");
      add_remove(info.phone1);
      goto label; //USING THE GOTO FUNCTION TO GO TO THE DESIRED POSITION
    }
    else
    {
      fputs(info.phone1,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the 2nd phone number : ");
    scanf("%s",info.phone2);
    //CALLING THE MERGE FUNCTION TO SEE IF THE NAME ALREADY EXISTS
    if(merge(info.phone2)==1 && info.phone2[0]!='-')
    {
      system("clear");
      check=1;  
      printf("This telephone number already exists in the directory.\n");
      printf("\nThe following are the details of that contact: \n\n");
      similar(info.phone2);
      fputs(info.phone2,fp);
      fprintf(fp,"\t");
      add_remove(info.phone2);
      goto label;
    }
    else
    {
      fputs(info.phone2,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the email address : ");
    scanf("%s",info.email);
    if(merge(info.email)==1 && info.email[0]!='-')
    {
      system("clear");
      check=1;  
      printf("This email address already exists in the Directory.\n");
      printf("\nThe following are the details of that contact:\n\n");
      similar(info.email);
      fputs(info.email,fp);
      fprintf(fp,"\t");
      add_remove(info.email);
      goto label;
    }
    else
    {
      fputs(info.email,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the residential address : ");
    scanf("%s",info.address);
    fputs(info.address,fp);
    fprintf(fp,"\t");
    printf("Enter the occupation : ");
    scanf("%s",info.occupation);
    fputs(info.occupation,fp); 
    fprintf(fp,"\t");
    printf("Enter the date of birth in dd/mm/yyyy format : "); 
    scanf("%s",info.dob);
    fputs(info.dob,fp); 
    fprintf(fp,"\t");
    fprintf(fp,"\n");
    label: n--; 
    //USING PREFRENCE TO FINALIZE WHAT THE USER WANTS
           if(n>0)
           {
             system("clear");
             printf("Do you want to continue (Press 1 for YES and Press 0 for NO) : ");
             scanf("%d",&preference);
             if(preference==0)
               break;
             else if(preference!=1 && preference!=0)
             {
               printf("You are requested to give a proper response\n");
               scanf("%d",&preference);
	       if(preference==1)
                 continue;
               else
	         break;
             }
           }	 
  } 
  if(check==0)
    printf("✦✦✦✦✦ Data Accepted Successfully ✦✦✦✦✦\n");
  fclose(fp);
}
