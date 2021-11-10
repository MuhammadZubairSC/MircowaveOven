#include<stdio.h>//header file of built-in C library
#include<conio.h>//header file of built-in C library
#define MAX 12
void total_time(int *,int *,int *);//function prototype containing pointer as arguments
void total_time(int *p, int*q ,int *r)//implementation of the function
{ 
	char ch;// declaration of a variable of type character
a2://goto expression
printf("Enter Total Time of Cooking:");//displaying information
 printf("\nHours: ");//displaying hours
 scanf("%d",*(&p));// getting hours from the user
 printf("\nMinutes:");//displaying minutes
 scanf("%d",*(&q));// getting hours from the user
 printf("\nSeconds:");//displaying seconds
 scanf("%d",*(&r));// getting hours from the user
 getchar();//ignores a character input
 if((*p)==0 && (*q)==0 && (*r)==0) //when the input hours, minutes and second as zero
 { printf("\nPlease Enter a Valid time!\n");//display warning
	 goto a2;//redirect the compiler to again input time
 }
 if ((*p)<0 || (*q)<0 || (*r)<0)//if decidion to correct the values of minutes, seconds and hours if entered as negative
 { printf("Please Enter a Valid time!\n");//display warning
	 goto a2;//redirect the compiler to again input time
 }

 if ((*p)>24 && (*q)>60 && (*r)>60)//if the time exceed the limit of 24/60/60
 { printf("Please Enter a Valid time!\n");//display warning
	 goto a2;//redirect the compiler to again input time
 }

 if ((*p)>24 || (*p)<0 )//if the value of hours is greater than 24 or less than zero
 { printf("Minutes corrupted!! Please Enter a Valid time!\n");//display warning
	 goto a2;//redirect the compiler to again input time
 }

 if ((*q)>60 || (*q)<0 )//if the value of minutes is greater than 24 or less than zero
 { printf("Seconds corrupted!! Please Enter a Valid time!\n");//display warning
	 goto a2;//redirect the compiler to again input time
 }

  if ((*r)>60 || (*r)<0 )//if the value of seconds is greater than 24 or less than zero
 { printf("Please Enter a Valid time!\n");//display warning
	 goto a2;//redirect the compiler to again input time
 }
  printf("Do you want to reset the time press \n'Y' for yes\n'N' for no.");//ask the user if he/she wants to reset the timer or not
  scanf("%c",&ch);// getiing input from the user
  if((ch=='Y')||(ch=='y'))// if the user enter Y or y then only the construct work
  {
	 goto a2;//redirect the compiler to input the data again
  }
}//end of the header file