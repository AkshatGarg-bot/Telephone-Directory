#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"partial_compare.h"
#include"print2Dgroup.h"

void group_viewing(void)
{
  system("clear");
  char group_name[30], single_contact[2000], details[7][175], group_name_check[100];
  int i, j, row, column, serial_number=1;
  printf("Please enter a name of the already created group you wish to view: ");
  scanf("%s",group_name);
  printf("Following are the details of the Group ❂❂  %s  ❂❂ : \n\n",group_name); 
  strcat(group_name,".txt");
  FILE* fp_group=fopen(group_name,"a+"); //opening the file of that group.
  while(fgets(single_contact,1999,fp_group))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++) //loop that makes the 2d array of the contact.
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
    print2Dgroup(details,serial_number); //call the printing function for displayning data in fancy manner.
    for(i=0;i<7;i++) //Nullification for furthur use.
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
    serial_number++; //serial number of contacts in group.
  }
  fclose(fp_group);
}
