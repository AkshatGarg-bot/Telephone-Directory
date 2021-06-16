#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"password.h"
#include"add_contact.h"
#include"search.h"
#include"add_contact.h"
#include"delete_contact.h"
#include"edit_contact.h"
#include"group_making.h"
#include"group_viewing.h"
#include"starring.h"
#include"view.h"

void search();

int main(void)
{
    int pass=password();
    if(pass==1)
    {
      printf("        ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬\n");
      printf("        ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬\n");
      printf("        ✬ ✬      WELCOME TO THE TELEPHONE DIRECTORY     ✬ ✬\n");
      printf("        ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬\n");
      printf("        ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬ ✬\n\n");
      int again=1;
      while(again)
      {
        printf("You are requested to select the appropriate option\n");
        printf("1 >> Search a contact\n2 >> View all contacts\n3 >> Add new contact\n4 >> Edit an existing contact\n5 >> Delete an existing contact\n");
        printf("6 >> Making a new group\n7 >> Viewing existing group details\n8 >> Managing Stared and Spammed contacts\n9 >> Reset everything to  default\n10 >> Close the directory");
        printf("\n\nEnter your choice: ");
        int selection;
        scanf("%d",&selection);
        switch(selection)
        {
	    case 1: search();	
	            break;
   
       	    case 2: view();
  	            break;
	  
            case 3: add_contact();
	            break;
	  
            case 4: edit_contact();
	            break;
          
            case 5: delete_contact();
                    break;
         
            case 6: group_making();
                    break;
  
            case 7: group_viewing();
                    break;   
    
            case 8: starring();
                    break;
  
            case 9: system("cp default.txt data_base.txt");
	             break;

            case 10: again=0;
                     break;
  
            default: printf("You are requested to make a VALID choice.");
                     break;   
        }
        if(selection!=10)
        {
          printf("Would you like to get the MAIN MENU displayed again?\n");
          printf("Enter 1 if your answer is YES.\n");
          printf("Enter any other number if your answer is NO.\n");
          scanf("%d",&again);
          system("clear");
        }
        if(again!=1 || selection==10)
        {
          again=0;
          printf("✌ ✌ ✌ ✌ ✌ ✌ ✌  THANK-YOU ✌ ✌ ✌ ✌ ✌ ✌ ✌\nYou Have Successfully EXITED The e-Telephone-Directory.\n");
        }
      }
    }
}
