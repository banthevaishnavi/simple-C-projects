#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int guess;
    int random;
    int no_of_attempts=0;
    srand(time(NULL));
    
    printf("\n hi!!  \n let's play the guessing number game.\n");
    random=rand()%100+1;
   
    do{
        printf("\n please... guess the random number between (1 to 100):\n");
        scanf("%d",&guess);
        no_of_attempts++;

        if(guess<random)
        {
            printf("\n guess a larger number.\n");

        }
        else if(guess>random)
        {
            printf("\n guess a smaller number.\n");
        }
        else{
           printf("\n congratulations!!you guessed correct number in %d attempts", no_of_attempts); 
        }

    }while(guess!=random);

    printf("\n glad to play with you!! \n");
    printf("\n developed by:vaishnavi banthe\n");
    printf("\nthankyou\n");
}







