#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
void fill_time(char*,int);
void fill_date(char*);
void clr_scrn();
int input_format();
int main()
{
  
  int format=input_format();
  char time[50],date[100];
  while(1)
  {
  

  fill_time(time,format);
  fill_date(date);
  clr_scrn();
   printf("\n\n current time:%s",time);
   printf("\n current date:%s",date);
   printf("\n\n\n\n\n\n\n\n\n");
   sleep(1);
  }
  return 0;
}
void clr_scrn()
{
  #ifdef _WIN34
  system ("cls");
  #else
  system("clear");
  #endif
}
int input_format()
{
  int format;
printf("choose a time format:\n ");
  printf("\n 1)24 hour format.");
  printf("\n 2)12 hour format.");
  printf("\n choose(1 or 2):",format);
   scanf("%d",&format);
   return format;
}
void fill_time(char* buffer,int format)
{
 
  
  time_t raw_time;
  struct tm *current_time;
  
  time(&raw_time);

  current_time=localtime(&raw_time);
   
  if(format==1)
  {
strftime(buffer,50,"%H:%M:%S",current_time);}
 else if(format==2)
 {
strftime(buffer,50,"%I:%M:%S:%p",current_time);
}

}

void fill_date(char* buffer)
{
  time_t raw_time;
  struct tm *current_time;
  time(&raw_time);
  current_time=localtime(&raw_time);
  strftime(buffer,100,"%A %B %d %Y",current_time);

}
