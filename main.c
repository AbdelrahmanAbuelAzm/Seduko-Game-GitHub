#include <stdio.h>
#include <stdlib.h>
#include"seduko.h"

int seduko[9][9];

int seduko1[9][9]=
{
    {0,8,0,1,0,0,0,0,0},
    {0,0,7,0,0,0,0,5,0},
    {0,3,0,0,0,5,1,2,0},
    {0,0,0,9,0,0,6,0,0},
    {0,0,0,0,6,3,0,8,4},
    {3,6,4,2,0,0,0,0,1},
    {7,2,0,0,0,6,4,9,8},
    {0,4,9,5,0,0,0,0,7},
    {0,0,0,0,0,0,0,0,0}

};
int seduko2[9][9]=
{
    {5,0,7,2,0,0,0,9,0},
    {0,0,6,0,3,0,7,0,1},
    {4,0,0,0,0,0,0,6,0},
    {1,0,0,4,9,0,0,0,7},
    {0,0,0,5,0,8,0,0,0},
    {3,6,4,2,0,0,0,0,1},
    {0,7,0,0,0,0,0,0,9},
    {2,0,9,0,8,0,6,0,0},
    {0,4,0,0,0,9,3,0,8}

};
int seduko3[9][9]=
{
    {0,9,1,0,7,0,0,0,0},
    {2,0,3,0,0,0,0,5,0},
    {0,0,0,4,0,2,9,0,7},
    {0,0,2,8,0,6,0,0,9},
    {0,0,0,0,0,0,0,0,0},
    {9,0,0,1,0,4,6,0,0},
    {1,0,5,2,0,7,0,0,0},
    {0,8,0,0,0,0,5,0,1},
    {0,0,0,0,1,0,7,6,0}

};
int constArr[9][9]={0};

int main()
{

    int row,col,num;
    sedukoLevel();
    sedukoConstNumbers(constArr);
    sedukoPrint(seduko);

    while(!(sedukoEnd()))
    {

         if(sedukoScanNumber(&row,&col,&num)==1)
         {
             sedukoInsertNumbers(row,col,num);
         }

    }


    return 0;
}