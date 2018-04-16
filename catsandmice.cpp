/*cats and mice occupies one home
they have maked a deal 
mice can steal the food pieces of the cats upto cat never the mice
func1
pthread_mutex_lock
if(cat sees mice)
    then must eat the mice
else 
    lose with all of thier cat friends
    pthread_mutex_unlock
attributes are the 
x:
    NUMBOWLS cat food dishes
    NUMCATS cats
    NUMMICE mices
pthread_mutex_lock
if(numcats==numbowls && numcats==nummice)
if(cat eating)
    at the food dish any mice is attemting seen and eaten 
else if(they aren't eating)
    cats cannot see the mice
else 
   nither the cat or the mice one of should be strave
else
	exit;
goto x;
pthread_mutex_unlock
*/
#include<stdio.h>
#include<pthread.h>
void check2();
void check1();
int NumBowls;
int NumCats;
int NumMice;
int i;
int x;
pthread_mutex_t l;
int main()
{
   
    pthread_mutex_init(&l,NULL);
    pthread_t th1,th2;
    pthread_create(&th1,NULL,check2,NULL);
    pthread_create(&th2,NULL,check1,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    printf("**********This is the END****************\n");
}
void check1()
{
	int cat;
    int mice;
    int c;
    pthread_mutex_lock(&l);
   	printf("MICE and CAT occupied a home \n");
    printf("They have maked a deal for the food \n");
    printf("mice can steal the food pieces of the cats upto cat never the mice \n");
    printf("press 0 or 1 to continue the fighting between the cat and mice \n");
    scanf("%d",&c);
    if(c == 1)
    {
        printf("cat must and should eat the mice \n");
    }
    else
    {
        printf("lose with all of thier cat friends \n");
        
    }
   	pthread_mutex_unlock(&l);
}
void check2()
{
    pthread_mutex_lock(&l);
   
    printf("NumBowls For the food for the cats \n");
    printf("NumCats For the number of the in house\n");
    printf("NumMice For the number of the mice in the home \n");
    x:
	printf("enter the number of Bowls in the house :\n");
    scanf("%d",&NumBowls);
    printf("enter number of the cats in the house: \n");
    scanf("%d",&NumCats);
    printf("enter the number of the mices in the house: \n");
    scanf("%d",&NumMice);
    if(NumBowls==NumCats && NumCats==NumMice)
    {
    printf("press 0 or 1 to continue the fighting between the cat and mice OR press the not equal to 1 it refers to the nither the cat or the should strave");
    scanf("%d",&i);
    if(i==1)
    {
       printf(" The is to eating of the cat any mice tried to eat the food in the dishes cat will eat them: \n ");
    }
    else if(i==0)
    {
        printf("cats aren't eating so,They can't see the mice eating of the food: \n");
    }
    else
    {
        printf("nither in them one should be strave");
    }
    }
    else
    {
        printf("sorry your's bowls and the cats are not equal or cats and mices are not equal:\n ");
        printf("PLEASE ENTER THE EQUAL NO OF CATS AND BOWLS AND MICE:\n");
    }
    goto x;
   pthread_mutex_unlock(&l);
}
