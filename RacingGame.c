#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

//*********FUNCTION PROTOTYPES*************
void printTrack(int TortoisePos, int HarePos);
int RandomNumberGenerate();
void Tortoise(int currentPosition);
void Hare(int currentPositon);
//*****************************************
int RandomGen;
RandomGen = 0; //For the position
int TortoisePosition;
TortoisePosition = 1;
int HarePosition;
HarePosition = 1;

int main()
{
    //SEED FOR RANDOM NUMBER
    int seed;
    printf("ENTER AN INT : ");
    scanf("%i", &seed);
    srand(seed);
    //*********************
    int KeepRunning = 0; //TRUE
    printf("BANG !!!\n");
    printf("AND THEY ARE OFF !!!\n");
    while(KeepRunning == 0)
    {
        //Move the Tortoise
        Tortoise(TortoisePosition);

        //Move the Hare
        Hare(HarePosition);

        printTrack(TortoisePosition, HarePosition);
        if(TortoisePosition == 70 && HarePosition == 70)
        {
            printf("It's a tie\n");
            KeepRunning = 1; //FALSE
        }
        if(TortoisePosition == 70)
        {
            printf("TORTOISE WINS !!!\n");
            KeepRunning = 1;
        }
        if(HarePosition == 70)
        {
            printf("Hare wins\n");
            KeepRunning = 1;
        }
        //WAIT
        Sleep(200);
    }
}

//********** HELPER METHODS***************
//print the track T and H
void printTrack(int TortoisePos, int HarePos)
{
    int i;
    //Tortoise < Hare
    if(TortoisePos < HarePos)
    {
        printf("|");
        for(i = 1; i <= TortoisePos-1; i++)
            printf(" ");
        printf("T");
        for(i = TortoisePos+1; i <=HarePos-1; i++)
            printf(" ");
        printf("H");
        for(i = HarePos+1; i <= 70; i++)
            printf(" ");
        printf("|\n");
    }
    if(TortoisePos > HarePos)
    {
        printf("|");
        for(i = 1; i <= HarePos-1; i++)
            printf(" ");
        printf("H");
        for(i = HarePos+1; i <=TortoisePos-1; i++)
            printf(" ");
        printf("T");
        for(i = TortoisePos+1; i <= 70; i++)
            printf(" ");
        printf("|\n");
    }
    if(TortoisePos == HarePos)
    {
        printf("|");
        for(i = 1; i <= HarePos-1; i++)
            printf(" ");
        printf("OUCH!!!");
        for(i = HarePos+7; i <=70; i++)
            printf(" ");
        printf("|\n");
    }
}
//Generate a random number between the range
int RandomNumberGenerate()
{
    return (1+(int)(10.0*rand()/RAND_MAX + 0.0));
}
void Tortoise(int currentPosition)
{
    RandomGen = RandomNumberGenerate();
    //Fast Plod
    if(RandomGen >= 1 && RandomGen <= 5)
    {
        if(TortoisePosition+3 > 70)
            TortoisePosition = 70;
        else
            TortoisePosition+=3;
    }
    //Slip
    if(RandomGen >= 6 && RandomGen <= 7)
    {
        if(TortoisePosition-6 < 1)
            TortoisePosition = 1;
        else
            TortoisePosition-=6;
    }
    //Slow Plod
    if(RandomGen >= 8 && RandomGen <= 10)
    {
        if(TortoisePosition+1 > 70)
            TortoisePosition = 70;
        else
            TortoisePosition+=1;
    }
}
void Hare(int currentPositon)
{
    RandomGen = RandomNumberGenerate();
    //SLEEP
    if(RandomGen >= 1 && RandomGen <= 2)
    {

    }
    //BIG HOP
    if(RandomGen >= 3 && RandomGen <= 4)
    {
        if(HarePosition + 9 > 70)
            HarePosition = 70;
        else
            HarePosition +=9;
    }
    //BIG SLIP
    if(RandomGen >= 5 && RandomGen <= 5)
    {
        if(HarePosition - 12 < 1)
            HarePosition = 1;
        else
            HarePosition-=12;
    }
    //SMALL HOP
    if(RandomGen >= 6 && RandomGen <= 8)
    {
        if(HarePosition + 1 > 70)
            HarePosition = 70;
        else
            HarePosition +=1;

    }
    //SMALL SLIP
    if(RandomGen >= 9 && RandomGen <= 10)
    {
        if(HarePosition - 2 < 1)
            HarePosition = 1;
        else
            HarePosition-=2;
    }
}
