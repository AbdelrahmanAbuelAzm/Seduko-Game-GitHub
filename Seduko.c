#include"seduko.h"
extern int seduko[9][9];
extern int seduko1[9][9];
extern int seduko2[9][9];
extern int seduko3[9][9];
extern int constArr[9][9];

int checkRow(int row,int num)
{
    int col;
    for(col=0; col<9; col++)
    {
        if(seduko[row][col]==num)
        {

            return 0;
        }
    }
    return 1;
}

int checkCol(int col,int num)
{
    int row;
    for(row=0; row<9; row++)
    {
        if(seduko[row][col]==num)
        {
            return 0;
        }
    }
    return 1;
}
int checkCube(int row,int col,int num)
{
    row=(row/3) *3;
    col=(col/3) *3;

    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(seduko[row+r][col+c]==num)
            {
                return 0;
            }
        }
    }
    return 1;
}
void sedukoPrint(int seduko[][9])
{
    int row,col;

    for(row=0; row<9; row++)
    {
        if(row%3==0)    // to make cube border
        {
            yellow();
            printf("==================================================\n");
            reset();
        }
        else
        {
            whiteBlue();
            printf("--------------------------------------------------\n");
            reset();
        }
        for(col=0; col<9; col++)
        {
            if(col%3==0)  // to make cube border
            {
                yellow();
                printf("||");
                reset();
            }
            if(seduko[row][col]== 0)  // to print space in case of no number
            {
                if(col%3!=0)
                {
                    whiteBlue();
                    printf("|");
                    reset();
                }
                printf("    ");
            }
            else
            {
                if(col%3!=0)
                {
                    whiteBlue();
                    printf("|");
                    reset();
                }
                if(constArr[row][col]==1) // to print const numbers in red
                {
                    red();
                    printf("%3d ",seduko[row][col]);
                    reset();
                }
                else // to print add numbers from user
                {
                    magenta();
                    printf("%3d ",seduko[row][col]);
                    reset();

                }

            }
        }
        yellow();
        printf("||");
        reset();
        printf("\n");

    }
    yellow();
    printf("==================================================\n");
    reset();
    printf("\n");
}
int sedukoScanNumber(int *row,int *col,int *num)
{
    lightGreen();
    printf("enter row number:");
    scanf("%d",row);
    printf("\nenter column number:");
    scanf("%d",col);
    reset();
    ////////
    if(checkConstatntNumbers(*row,*col) ==0)
    {
        return 0;
    }
    else
    {
        lightGreen();
        printf("\nenter your number:");
        scanf("%d",num);
        reset();
        system("cls");
    }
    return 1;
}

void sedukoInsertNumbers(int row,int col,int num)
{
    if(checkRow(row,num)==1 && checkCol(col,num)==1 && checkCube(row,col,num)==1 )
    {
        seduko[row][col]=num;
        sedukoPrint(seduko);
        if (sedukoEnd())
        {
            system("cls");
            lightGreen();
            printf("Congratulations you win \n");
            reset();
        }
    }
    else
    {
        system("cls");
        sedukoPrint(seduko);
        red();
        printf("you insert wrong number,try again\n");
        reset();
    }
}
void sedukoConstNumbers(int constArr[][9])
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(seduko[i][j] !=0)
            {
                constArr[i][j]++;
            }
        }

    }
}
int checkConstatntNumbers(int row,int col)
{
    if(constArr[row][col] == 1)// check if the selected has initial value from user
    {
        system("cls");
        sedukoPrint(seduko);
        red();
        printf("you select constant number, try again\n");
        reset();
        return 0;
    }
    else
    {
        return 1;
    }
}

void sedukoLevel()
{
    int num,i,j;
    lightGreen();
    printf("Choose level you want to play\n1-Easy\n2-Medium\n3-Hard\n");
    scanf("%d",&num);
    reset();
    system("cls");
    if(num==1)
    {
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                seduko[i][j] = seduko1[i][j];
            }
        }

    }
    else if(num==2)
    {
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                seduko[i][j] = seduko2[i][j];
            }
        }
    }
    else if(num==3)
    {
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                seduko[i][j] = seduko3[i][j];
            }
        }
    }
}
int sedukoEnd()
{
    int i,j;
    for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if (seduko[i][j])
                {
                    return 0;
                }

            }
        }
        return 1;
}
void red ()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}
void blue()
{
    printf("\033[1;94m");
}
void whiteBlue()
{
    printf("\033[1;36m");
}
void magenta()
{
    printf("\033[1;35m");
}
void lightGreen()
{
    printf("\033[1;92m");
}
void reset ()
{
    printf("\033[0m");
}
