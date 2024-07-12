#include<stdio.h>
#include<unistd.h>
#include<time.h>
int const bar_length=50;
int const MAX_TASK=5;
void print_bar(task
);
void clear_screen();
typedef struct{
int id;
int progress;
int step;
}task;
int main()
{
  task task[MAX_TASK];
  srand(time(NULL));
  for(int i=0;i<MAX_TASK;i++)
  {
    task[i].id=i+1;
    task[i].progress=0;
    task[i].step=rand()%5+1;
  }
  int task_incomplete=1;
  while(task_incomplete)
  {
    task_incomplete=0;
    clear_screen();
    for(int i=0;i<MAX_TASK;i++)
    {
      task[i].progress+=task[i].step;
      if(task[i].progress>100)
      {
        task[i].progress=100;
      }
      else if(task[i].progress<100)
      {
          task_incomplete=1;
      }
      print_bar(task[i]);
    }
    sleep(1);
    printf("\n all tasks completed!!");
  }
 
  return 0;
}
void clear_screen()
{
  #ifdef _WIN32
  system("cls");
  #else
  printf("clear");
  #endif;

}
void print_bar(task task)
{
  
  
  int bar_to_show=(task.progress*bar_length)/100;
  printf("\nTask%d:[",task.id);
  
  for(int i=0;i<bar_length;i++)
  {
    if(i<bar_to_show)
    {
      printf("=");

    }else{
      printf(" ");
    }
  }
  printf("] %d%%",task.progress);

}