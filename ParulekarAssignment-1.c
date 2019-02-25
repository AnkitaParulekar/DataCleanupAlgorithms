/* Execution time comparison between Shuffle left, Converging pointer and Copy over algorithm.
Author : Ankita Parulekar */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffleLeftAlgorithm(int list[],int listSize);
void copyOverAlgorithm(int list[],int listSize);
void convergingPointersAlgorithm(int list[],int listSize);

int main()
{
int list[1000000];
clock_t start_t,end_t,total_t;
int listSize,i,randomNumber;
printf("Enter list size");
scanf("%d",&listSize);

for(i=0;i<listSize;i++)
 {
   randomNumber = rand()%120;
   if (randomNumber>100)
   {
 	randomNumber = 0;
   }
list[i]= randomNumber;
 }
 
/*for(i=0;i<listSize;i++)
 {
  printf("%d  ",list[i]);
}*/

//shuffle left algorithm
start_t=clock();
shuffleLeftAlgorithm(list,listSize);
end_t = clock();
total_t=(double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("Total time taken by CPU for shuffle left algorithm: %lu\n", total_t);

//Converging pointer algorithm
start_t=clock();
convergingPointersAlgorithm(list,listSize);
end_t = clock();
total_t=(double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("Total time taken by CPU for converging pointer algorithm: %lu\n", total_t);


//copy over algorithm
start_t=clock();
copyOverAlgorithm(list,listSize);
end_t = clock();
total_t=(double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("Total time taken by CPU for copy over algorithm: %lu\n", total_t);



return 0;
}


void shuffleLeftAlgorithm(int list[],int listSize)
{
  int left,right,legit,i;
  legit=listSize;
  for(i=0;i<listSize;i++)
  {
 	legit=listSize;
	left=i;
 	right=i+1;
       while(left<=legit)
	{
		if(list[left]>0)
		{		
		  left=left+1;
		  right=right+1;
		}
		else
		{
		  legit=legit-1;
		}
         }
          while(right<=listSize)
          {
		list[right-1]=list[right];
  		right=right+1;
          }
        right=left+1;
	}
  

/*printf("Shuffle left algorithm");
for(i=0;i<listSize;i++)
  {
	printf("%d  ",list[i]);
  }*/
}

void convergingPointersAlgorithm(int list[],int listSize)
{
  int legit,left,right,i;
  legit=listSize;
  for(i=0;i<listSize;i++)
  {
    left=i;
    right=listSize;
    while(left<right)
    {
	if(list[left]==0)
	 {
	   legit=legit-1;
	   list[left]=list[right];
	   right=right-1;
	 }
	else
	{
 	   left=left+1;
	}
      
     if(list[left]==0)
      {
	legit=legit-1;
      }
    }
  
  }


/*printf("Converging pointers algorithm");
for(i=0;i<listSize;i++)
  {
	printf("%d  ",list[i]);
  }*/
}

//Copy over algorithm
void copyOverAlgorithm(int list[],int listSize)
{
 int newList[listSize],oldPos,newPos,i;
 for(i=0;i<listSize;i++)
 {
 	oldPos=i;
	newPos=i;
   while(oldPos<=listSize)
   {
     if(list[oldPos]>0)
     {
	
	newList[newPos]=list[oldPos];
	newPos=newPos+1;
     }
     oldPos=oldPos+1;
   }
 }


/*printf("Copy over algorithm");
for(i=0;i<listSize;i++)
  {
	printf("%d  ", newList[i]);
  }*/
}

