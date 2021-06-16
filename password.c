//CREATING THE PASSWORD TO EBTER THE TELEPHONE DIRECTORY
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"string_compare.h"

int password(void)
{
  int ask, correct=0;
  char user[20];
  printf("Enter the USERNAME : ");
  scanf("%s",user);
  if(string_compare(user,"wewantfullmarks")==0) //USING OWN STRING COMPARE TO STOP THE CASE SENSITIVENESS OF THE DATA
  {
    char *password = getpass("Enter the PASSWORD : "); //USING GETPASS SO THAT THE USER CANNOT SEE THE DATA TYPED
    if(strcmp(password,"requestaccepted")==0)
    {
      correct=1;
      printf("✌ ✌ ✌ ✌ ✌  CONGRATULATIONS ✌ ✌ ✌ ✌ ✌\n\n");
    }
    else
    {
      printf("INVALID Password => ACCESS DENIED\n");
      printf("Enter 1 to re-enter the PASSWORD.\nEnter 0 to exit the e-Telephone Directory\n");
      scanf("%d",&ask);
      if(ask==1)
      {
        char *password1 = getpass("Re-enter Password : "); //GIVING THE USER TWO TRIES IF HE HAS ENTERED THE WRONG PASSWORD
	if(strcmp(password1,"requestaccepted")==0)
        {
          correct=1;
	  printf("✌ ✌ ✌ ✌ ✌  CONGRATULATIONS ✌ ✌ ✌ ✌ ✌\n\n");
        }
	else
	  printf("You cannot access the e-Telephone-Directory now, as you have entered the wrong password TWICE");
      }
      if(ask==0)
  	  printf("✌ ✌ ✌ ✌ ✌  THANK-YOU ✌ ✌ ✌ ✌ ✌\nYou Have Successfully EXITED The e-Telephone-Directory.\n\n");
    }		
  } 
  else
    printf("INVALID USERNAME");
  return correct;
}
