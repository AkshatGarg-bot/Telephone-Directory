#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int partial_compare(char small[100], char large[100])
{
  int compare, count, check=0, index=0, i, j, k, s=strlen(small), l=strlen(large), array[100];
  if(s<=l) //length of big string must be longer than small one.
  {
    for(i=0;i<l;i++)
    {
      if(small[0]==large[i] || abs((int)small[0]-(int)large[i])==32) //for capital and small alphabets.
      {
        array[index]=i;//storing the locations of the big string that match with the first character of small one.
        index++;
      } 
    }
    for(i=0;i<index;i++)
    {
      count=0;
      for(j=array[i],k=0; j<array[i]+s; j++,k++)
      {
        if(large[j]==small[k] || abs((int)small[k]-(int)large[j])==32)
        count++;
      }
      if(count==s) //checking for the presence of the small string in every part of big one.
      { 
        check=1;
        compare=0;
        break;
      }
    }
    if(check==0) //If no match is found.
      compare=1;
  }
  else
    compare=1;
  return compare;
}
