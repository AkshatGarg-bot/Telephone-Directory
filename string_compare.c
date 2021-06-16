//PROGRAM TO STRING COMPARE BY TAKING CAPITAL AND SMALL ALPHABETS EQUAL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int string_compare(char array1[100], char array2[100])
{
  int compare=0, count=0, i;
  if(strlen(array1)==strlen(array2))
  {
    for(i=0;i<strlen(array1);i++)
    {
      if(array1[i]==array2[i] || abs((int)array1[i]-(int)array2[i])==32) //USING ASCII TO IMPLIMENT THE DESIRED STRING DELETE FUNCTION
      count++;  //USING COUNT TO COMPARE
    }
    if(count!=strlen(array1))
      compare=1;
  }
  else
    compare=1;
  return compare;
}
