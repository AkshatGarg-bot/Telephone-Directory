#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"partial_compare.h"

struct person
{
    char name[50];
    char phone1[15];
    char phone2[15];
    char email[50];
    char address[100];
    char occupation[10];
    char dob[10];
}person;

void del2(char name[],char file_name[50])//function that makes new file and deletes the old one.
{
  char single_contact[2000], details[7][175];
  int check=0, i, j, row, column;
  FILE* fp=fopen(file_name,"a+");	
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
    if(partial_compare(name,details[0])==1)
      fputs(single_contact,temp);
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  remove(file_name);
  rename("temp.txt",file_name);
  fclose(fp);
}  

void starring(void)
{
    system("clear");
    FILE *data,*star;
    int choice,found;
    char name[50];
    printf("Enter your selected choice\n1. For viewing starred\n2. For viewing spammed\n3. For starring a contact\n4. For spamming a contact\n5. Removing a starred contact\n6. Removing a spammed contact\n");
    scanf("%d",&choice);
    system("clear");
    switch(choice)
    {
	case 1: //displaying the sorted list of starred contacts.
	    system("sort star.txt");
	    break;
	case 3:
	    data=fopen("data_base.txt","a+");
	    printf("Enter the name of the person to be starred: "); //entering name to be starred.
	    scanf("%s",name);
	    while(!feof(data))
	    {
		fscanf(data,"%s %s %s %s %s %s %s",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		if (partial_compare(name,person.name)==0)
		{
		    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		    found=1;
		    break;
		}
	    }
	    if(found==1) //if found then edit.
	    {
		star=fopen("star.txt","a");
		fprintf(star,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		printf("\nData starred succefully\n");
		fclose(star);
		fclose(data);
	    }
	    else
		printf("Enter a correct name");
	    break;
	case 2:
	    system("sort spam.txt");
	    break;
	case 4:
	    data=fopen("data_base.txt","a+");
	    printf("Enter the name of the person to be spammed: ");
	    scanf("%s",name);
	    while(!feof(data))
	    {
		fscanf(data,"%s %s %s %s %s %s %s",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		if (partial_compare(name,person.name)==0)
		{
		    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		    found=1;
		    break;
		}
	    }
	    if(found==1)
	    {
		star=fopen("spam.txt","a");
		fprintf(star,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		printf("\nData spammed succefully\n");
		fclose(star);
		fclose(data);
	    }
	    else
	        printf("Enter valid name");
	    break;
	case 5: //unstarring a contact
	    data=fopen("star.txt","a+");
	    printf("Enter the name of the person to be removed from starred: ");
	    scanf("%s",name);
	    while(!feof(data))
	    {
		fscanf(data,"%s %s %s %s %s %s %s",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		if (partial_compare(name,person.name)==0)
		{
		    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		    found=1;
		    break;
		}
	    }
	    if(found==1)//if its 
	    {
                del2(person.name,"star.txt");
		printf("\nContact Unstarred succefully\n");
	    }
	    else
	        printf("\nEnter valid name\n");
	    break;

	case 6: //unspamming a contact
	    data=fopen("spam.txt","a+");
	    printf("Enter the name of the person to be removed from spammed: ");
	    scanf("%s",name);
	    while(!feof(data))
	    {
		fscanf(data,"%s %s %s %s %s %s %s",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		if (partial_compare(name,person.name)==0)
		{
		    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",person.name,person.phone1,person.phone2,person.email,person.address,person.occupation,person.dob);
		    found=1;
		    break;
		}
	    }
	    if(found==1)
	    {
                del2(person.name,"spam.txt");
		printf("\nContact unspammed succefully\n");
	    }
	    else
	        printf("Enter valid name");
	    break;
    }
}
