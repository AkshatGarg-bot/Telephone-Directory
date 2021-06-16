//MAKING EDIT CCONTACT TO EDIT THE DETAILS OF THE USER WHICH A PERSON WANT TO
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"string_compare.h"

struct person
{
  char name[50];
  char phone1[15];
  char phone2[15];
  char email[50];
  char address[100];
  char occupation[10];
  char dob[10];
}x;

void new_files(char name[]) 
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

void edit_contact(void) //ASKS THE NAME OF THE USER AND THEN ASKS THE DETAILS WHICH YOU WANT TO EDIT
{
  char name[50];
  FILE *data=fopen("data_base.txt","a+");
  int choice,found=0;
  printf("Enter the name of the contact to be EDITED : ");
  scanf("%s",name);
  while(!feof(data))
  {
    fscanf(data,"%s %s %s %s %s %s %s",x.name,x.phone1,x.phone2,x.email,x.address,x.occupation,x.dob);
    if(string_compare(name,x.name)==0) //COMPAIRING THE CONTACT USONG NAME IF NOT FOUND THEN BREAK
    {
      found=1;
      break;
    }
  }
  if(found==1)
  {
    system("clear");
    new_files(name);
    data=fopen("data_base.txt","a+");
    printf("Which of the following information would you like to change:\n1. Name\n2. Phone number1\n3. Phone number2\n4. Email id\n5. address\n6. Occupation\n7. Date of birth\n");
    scanf("%d",&choice);
    switch (choice)  //USING THE SWITCH CASE TO MAKE THE USER SELECT WHICH THE USER WANT TO EDIT AND THEN SCANNING THE DATA
    {
      case(1): printf("Type the new name for the contact: ");
	       scanf("%s",x.name);
	       break;
		
      case(2): printf("Type the new phone number 1: ");
	       scanf("%s",x.phone1);
	       break;

      case(3): printf("Type the new phone number 2: ");
	       scanf("%s",x.phone2);
	       break;
	    
      case(4): printf("Type the new Email id: ");
	       scanf("%s",x.email);
	       break;
      
      case(5): printf("Type the new address: ");
	       scanf("%s",x.name);
	       break;
		
      case(6): printf("Type the new occupation: ");
	       scanf("%s",x.email);
	       break;
		
      case(7): printf("Type the new occupation: ");
               scanf("%s",x.dob);
	       break;

      default: printf("You are requested to make a VALID choice.\n");
               break;	
    }
    fprintf(data,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",x.name,x.phone1,x.phone2,x.email,x.address,x.occupation,x.dob);
    printf("\n♣ ♣ ♣ ♣ ♣ Contact EDITED Successfully ♣ ♣ ♣ ♣ ♣\n\n");
    fclose(data);
  }
  else
    printf("\n♣ ♣ ♣ ♣ ♣ Contact NOT Found ♣ ♣ ♣ ♣ ♣\n");
}
