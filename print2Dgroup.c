#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print2Dgroup(char array2d[7][175], int serial_number)
{
  //this function prints the contacts of a group in a fancy maner.
  //along with serial numbers.
  //the details that do not exist are omitted
  printf("Contact Number #%d\n",serial_number);
  array2d[1][10]='\0';
  int l=0, i;
  for(i=0;i<7;i++)
  {
    if(strlen(array2d[i])>l)
      l=strlen(array2d[i]);
  }
  for(int i=1;i<=26+l;i++)
    printf("✯");
  printf("\n✯ Name                : %s ",array2d[0]);
  for(i=1;i<=l-strlen(array2d[0]);i++)
    printf(" ");
  printf("✯"); 
  printf("\n✯ Phone Number        : %s ",array2d[1]);
  for(i=1;i<=l-strlen(array2d[1]);i++)
    printf(" ");
  printf("✯"); 
  if(array2d[2][0]!='-')
  {
    array2d[2][10]='\0';
    printf("\n✯                       %s ",array2d[2]);
    for(i=1;i<=l-strlen(array2d[2]);i++)
      printf(" ");
    printf("✯"); 
  }
  if(array2d[3][0]!='-')
  {
    printf("\n✯ Email Address       : %s ",array2d[3]);
    for(i=1;i<=l-strlen(array2d[3]);i++)
      printf(" ");
    printf("✯"); 
  }
  if(array2d[4][0]!='-')
  {
    printf("\n✯ Residential Address : %s ",array2d[4]);
    for(i=1;i<=l-strlen(array2d[4]);i++)
      printf(" ");
    printf("✯"); 
  }
  if(array2d[5][0]!='-')
  {
    printf("\n✯ Occupation          : %s ",array2d[5]);
    for(i=1;i<=l-strlen(array2d[5]);i++)
      printf(" ");
    printf("✯"); 
  }
  if(array2d[6][0]!='-')
  {
    array2d[6][10]='\0';
    printf("\n✯ Date of Birth       : %s ",array2d[6]);
    for(i=1;i<=l-strlen(array2d[6]);i++)
      printf(" ");
    printf("✯"); 
  }
  printf("\n");
  for(int i=1;i<=26+l;i++)
    printf("✯");
  printf("\n\n");
}
