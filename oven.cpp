/*
programmed by:Muhammad Zubair Salahuddin Chishti
Date:20-10-2014
Lecturer:Miss Saeedah Al-Sadat Tabatabael
Topic:Micro wave Oven

*/
#include<stdio.h>//header files of built-in C library
#include<conio.h>//header file of built-in C library 
#include<windows.h>//header file of built-in C library 
#include<stdlib.h>//header file of built-in C library 
#include"totaltime.h"//header file of programmer defined library
void welcome();//function prototype (non return function of zero parameter)
void power();//function prototype (non return function of zero parameter)
void clock_2(int,int,int,int ,int [10],int [10],int [10],char [3][9],int [11],int);//function prototype (non return function of 10 parameters)
void LED();//function prototype (non return function)
void main()
{
 int h=0,m=0,s=0,i=0,h1[3],m1[3],s1[3],j=0,p,level[11],menu=0;//declaration of the variables of type int
 char mode,option='y';// declaration of the variable of type char
 char pl[3][9]={"Maximum*","Moderate","Minimum*"};// declaration of the two-dimensional string array 
 char coun[10][5]={"1st","2nd","3rd","4th","5th","6th","7th","8th","9th","10th"};// declaration of the two-dimensional string array
 a1://goto variable
 welcome(); // call of the function of zero parameter
 scanf("%d",&menu);//get input from user
switch (menu)//switch construct for main menu
	{
 case 1://condition when the user enter 1
 {
total_time(&h,&m,&s);//calling function by references
 system("cls");//clear screen
 power();// calling the function power
 mode=_getche();// getting the character input from the user to choose from the options displayed in power function
 switch(mode)//switch construct for mode of cooking
 {
     case 'S'://character case containig the lower letter and upper letter case aplhabet as choice
     case 's':
		 {
	    printf("\n\nEnter Power Level for whole cooking time\n1)Maximum\n2)Moderate\n3)Minimum\n\n\nNOTE:Timer will start at %d : %d : %d and end at 00:00:00\n",h,m,s);//displaying option
	    scanf("%d",&p);//get value from user
		switch(p)//switch of powerlevel of cooking
		{
			case 1://when the user enter option 1
		        {printf("%s Level selected\n",pl[0]);//display the powerlevel high
				break;}// to go out from the decisional construct
		    case 2://when the user enter option 2
				{printf("%s Level selected\n",pl[1]);//display the powerlevel medium
				break;}// to go out from the decisional construct 
		    case 3://when the user enter option 3
				{printf("%s Level selected\n",pl[2]);//display the powerlevel low
				break;}// to go out from the decisional construct 
			default://when the user mistakenly enter the number other than listed numbers
				{p=2;//assigning the default value as medium
				break;}// to go out from the decisional construct 
		}
		i=11;//assigning 11 to the int i
		clock_2(h,m,s,i,h1,m1,s1,pl,level,p);//calling the function of clock_2 by value
		 break;// to go out from the decisional construct
		 }
     case 'n'://character case containig the lower case and upper case aplhabet as choice
     case 'N':
		 {
		printf("\nYou are allowed to specify maximum of 10 Power Levels:\nMaximum\nModerate\nMinimum \n\nNOTE:Timer will start at %d : %d : %d and end at 00:00:00",h,m,s);//displaying information

            while (( option =='y')||( option =='Y'))//while loop begins if the user input is either y or Y
          {
               if (i>3)//when counter i exceeds 9
               {
				   printf("\n\n You have already specified 10 Power Level!");//display information
				   Sleep(1000);// wait for one second
				   break;//  exit from the loop
			   }
			   a3://goto expression
               printf("\n\nEnter %s Power Level:\nPress",coun[i]);//display the content of string coun which changes as the counter i changes
			   printf("\n1)Maximum\n2)Moderate\n3)Minimum\n");//displaying option
		  scanf("%d",&level[i]);//gets the i value of numeric array level
		switch(level[i])// switch for multiple power level
		{
			case 1:// when the user enter option 1
		        printf("%s Level selected\n",pl[0]);
		        break;//exit from switch construct
		    case 2://when the user enter option 2
				printf("%s Level selected\n",pl[1]);
		        break;//exit from switch construct
		    case 3://when the user enter option 3
				printf("%s Level selected\n",pl[2]);
		        break;//exit from switch construct
			default:// when user mistakenly enter any input other than 1,2 or 3
				printf("Error!Please enter a valid integer\n");//display error
				goto a3;//redirect the value of level[i] to initialize again
				break;//exit from switch construct
		}
			   if (i==0) //when the counter i=0 the initial time should be the total time of cooking
			   { 
				   printf("NOTE:Initially your time should be same as: %d : %d : %d .",h,m,s);//displaying the set total time of cooking by the user
				   h1[i]=h;//assign the initial value of h1[0] as h
				   m1[i]=m;//assign the initial value of m1[0] as m
				   s1[i]=s;//assign the initial value of s1[0] as s
			   }
			   else// when the counter i>0
			   {
					   printf(" At what time remaining you want to start %s Power Level",pl[level[i]-1]);//display the power level which is selected by the user such as in case 1, 1 will be stored in level[i] so to display power level[0] the index of level[i] should also be 0 which is acheived by subtracting level[i] from 1 to display the high as power level[1-1=0]
               printf("\n Hours: ");//ask the user to enter hours
               scanf("%d",&h1[i]);// prompt the user to enter hour for counter i
               printf("\n Minutes: ");//ask the user to enter minutes
               scanf("%d",&m1[i]);// prompt the user to enter minutes for counter i
               printf("\n Second: ");//ask the user to enter second
               scanf("%d",&s1[i]);// prompt the user to enter second for counter i
			   }
                   if (i<=3)//when counter i is within the limit of ten 
                   {
                    printf("\n\nDo you want to specify more Power Levels? Press 'Y' for Yes or 'N' for No:");//ask the user whether he want to specify more power level or not
                    option=_getche();//get character input
                    ++i;//increment in counter i
				   }
			}
			clock_2(h,m,s,i,h1,m1,s1,pl,level,p);//calling the clock_2 function by value
			break;//exit from the while loop
		}
		default://if the user mistakenly enter any irrelevant option then default settings set by programmer comes in handy
          {  i=11;//assign 11 to counter i
		     p=2;//assign 2 to integer p
		clock_2(h,m,s,i,h1,m1,s1,pl,level,p);//calling the clock_2 function by value 
		 break;}//exit from switch construct
 }
 break;
 }
 case 2://when the user enter 2 from  main menu
		 {
			 printf("Program By Muhammad Zubair Salahuddin\n Exiting.......Please wait %c",2);//display data
			 Sleep(1000);//wait for 1 second
			 exit(0);//end the program
			 break;//exit from the switch construct
		 }
 default://if the user enter wrong choice
		{ printf("Enter a valid choice!\nPlease re-enter your choice again %c\n",2);//prompt the user to re enter the choice from the option
	     goto a1;//re direct the compiler to the specified point a1
		break;}//going out from the switch construct
 }
 goto a1;//re direct the compiler to the specified point a1
 fflush(stdin);//refresh the memory
 getchar();//display the result to the the user
 }

void clock_2(int h,int m,int s,int i,int h1[10],int m1[10],int s1[10],char pl[3][9],int level[11], int p)//function implementation
{
	system("cls");//clear the screen
	HANDLE Screen;//declaring a void pointer type
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);//retrieve the console to display output on the screen
	int x,y,j=0;// integer declaration
	 while((h!=-1)||(m!=-1)||(s!=-1))// while loop structures executes till the values of h or m or s is not equal to -1
	 {

   if(s==-1)//when s is equal to -1
   {s=59;}//59 is assigned to s
   if(m==-1)//when mis equal to -1
   {m=59;}//59 is assigned to m

   for(s;s>=0;s--)//the loop decreases till the second's value collides with -1
   {
    if (i==11)//when the counter i is equal to eleven
       {
        x=6, y=4;// assigning the value for x and y
        COORD P1={x, y};//assign the location of cursor,which is 6 bits from the left and 4 bit below from the top most line, to P1
        SetConsoleCursorPosition(Screen, P1);// set the console to defined cursor position to display the result from the particular section (P1) of screen
        printf("\nPower Level of whole cooking is %s",pl[p-1]);//display the selected power level for the single power mode
       }
	if(((h==h1[j])&&(m==m1[j])&&(s==s1[j]))&&(j<=9))//when values of total hours,minutes and second while decreasing matches the values stored in the array h1,m1 and s1 and j is under 10
                 {
                  x=6, y=4;// assigning the value for x and y
                  COORD P1={x, y};////assign the location of cursor,which is 6 bits from the left and 4 bit below from the top most line, to P1
                  SetConsoleCursorPosition(Screen, P1);// set console cursor position to display the result from the particular section (P1) of screen
                  printf("\nPower Level at this time is %s ",pl[level[j]-1]);//display the selected power levels for the multiple power mode
                  ++j;//counter increment
                 }
        x=15, y=12;// assigning the value for x and y ,locating the cursor at 15 bits position from the left and 12 bit below from the top most line.
        COORD P2={x, y};//obtain the location of P2 in terms of x and y
        SetConsoleCursorPosition(Screen, P2);// set the console to defined cursor position to display the result from the particular(P2) section of screen
        if(s<=9)//when the value second is less than or equal to 9
        {printf(":0%d",s);}//display seconds after zero digit
        else//if the value of seconds exceeds the 9
        {printf(":%d",s);}//display seconds
        x=10, y=12;// assigning the value for x and y 
        COORD P3={x, y};////assign the location of cursor,which is 10 bits from the left and 12 bit below from the top most line, to P3
        SetConsoleCursorPosition(Screen, P3);// set console cursor position to display the result from the particular section(P3) of screen

        if(m<=9)//when the value minutes is less than or equal to 9
        {printf(":0%d",m);}//display minutes
        else//if the value of minutes exceeds the 9
        {printf(":%d",m);}//display minutes
        x=5, y=12;// assigning the value for x and y 
        COORD P4={x, y};//assign the location of cursor,which is 5 bits from the left and 12 bit below from the top most line, to P4
        SetConsoleCursorPosition(Screen, P4);// set console cursor position to display the result on the particular section(P3) of screen

        if(h<=9)//when the value hours is less than or equal to 9
        {printf("0%d",h);}//display hours
        else//if the value of hours exceeds the 9
        {printf("%d",h);}//display hourss

        if((m==0) && (s==0))//when the value of minutes and seconds is equal to 0
        {--h;}//hours decrement
        if (s==0)//when only the value of seconds is equal to 0
        {--m;}//minutes decrement

        Sleep(1000);//wait for one second
   }
	 }
	 LED();//calling the function lED()
}

void LED()//LED() function implementation
{
	system("cls");//clear screen
	char f1[170]={"\t***********Thank you for using the application************\n***********Program by Muhammaad Zubair Salahuddin Chishti************\n\t\t***********TP033402************\n"};//declaration and assignment of string f1
	char *c1=&f1[0];//a character pointer that points ti the first element of f1
	int d=120,c=0,x,y;//declaring of integer d,c,x and assigninig the value 120 to d and 0 to c
	HANDLE hconsole,screen;//set the variables hconsole and screen as the type of void pointer
		screen=GetStdHandle(STD_OUTPUT_HANDLE);//assign the function console GetStdHandle of standard output parameter to make the buffer screen active
	hconsole= GetStdHandle(STD_OUTPUT_HANDLE);//assign the function console GetStdHandle of standard output parameter to make the buffer screen active
	system("COLOR F0");//change the color of the screen from standard settings to white background and black text color.
 for(int j=225;j>=119;j--)// for loop containing variable j of type integer and value 225, which change color of the highlighted part of the text and also its color when decreased
	{
		x=15,y=12;//the assignment of x as 15 and y as 12
         COORD a={x,y};////assign the location of cursor, which is 15 bits position from the left and 12 bit below from the top most line, to a
		SetConsoleCursorPosition(screen,a);// set the cursor position of the console to the disply the result on the particular section(a) of the screen
		SetConsoleTextAttribute(hconsole,d=j);// set the console screen to change the color of the printf statement and also highlights that particular portion on the screen
		printf("***********THE FOOD IS COOKED************\n");//display 
		Sleep(100);//wait for 0.1 second
 }
 	system("COLOR F0");//change the color of the screen from standard settings to white background and black text color otherwise there will be no character displayed only black highlight.
 for (*c1;*c1!='\0';c++)// a for loop for displaying each character of string
{
		printf("%c\n",*(c1+c));//display the characters of string
		if (c==169)//when the pointer reaches to the end of the string the infinite loop is avoided by stopping it
		{break;}//the compiler comes out from the loop
		Sleep(100);//wait for 1 second
}
 system("cls");//clear the screen
}
void welcome()//implementation of the function welcome()
{
	system("COLOR 4F");//change the color of the screen from standard settings to red background and white text color.
	printf("******************************************************************************\n");//display the output
	printf("---------------------------Welcome to Microwave Oven Menu----------------------\n");//display the output
	printf("*******************************************************************************\n");//display the output
	printf("Press\n1-->To Start the Program\n2-->To exit\n");//display the information
}
void power()//implementation of the function power()
{
	system("COLOR F4");// change the color of the screen from standard settings to white background and red text color.
	printf("******************************************************************************\n");//display the output
	printf("--------------------------------Power Mode Menu--------------------------------\n");//display the output
	printf("*******************************************************************************\n");//display the output
	printf("\nSet Mode and Power Level for cooking.\nNOTE:Default cooking Mode is Single and Default Power Level is Moderate.\n\nPRESS\n'S'-->For Single cooking Mode and \n'N'--> For Multiple cooking Modes\n");//display the information

}