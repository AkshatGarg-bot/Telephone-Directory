#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void group_making(void)
{
  system("clear");
  char group_name[30], single_contact[2000], name[50];
  int choice, index, i, j;
  printf("Please enter a name for your group : ");
  scanf("%s",group_name);
  strcat(group_name,".txt");
  FILE* fp_group=fopen(group_name,"a+");
  FILE* fp=fopen("data_base.txt","a+"); //opening file pointer.
  system("clear");
  printf("Names of people in your directory will appear one by one on the screen.\n");
  printf("Enter 1 if you want to add that particular person's contact details in the group, else enter any other number.\n"); 
  while(fgets(single_contact,1999,fp)) //loop for all printing names one by one.
  {
    index=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]=='\t')
        break;
      else
      {
        name[index]=single_contact[i];
        index++;
      }
    }
    name[index]='\0'; //stores the name of any line in the text file.
    printf("%s : ",name);
    scanf("%d",&choice); //user chooses whether to keep the contact or not.
    printf("\n");
    if(choice==1)
      fprintf(fp_group,"%s",single_contact);
    for(i=0;i<index;i++)
      name[i]='\0';
  }
  printf("⁂ ⁂ ⁂ ⁂ ⁂ Group Created Successfully ⁂ ⁂ ⁂ ⁂ ⁂\n\n");
  fclose(fp);
  fclose(fp_group);
}
