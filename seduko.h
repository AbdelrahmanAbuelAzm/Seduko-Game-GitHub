#ifndef SEDUKO_H_INCLUDED
#define SEDUKO_H_INCLUDED


int checkRow(int row,int num);
int checkCol(int col,int num);
int checkCube(int row,int col,int num);
void sedukoLevel();
void sedukoPrint(int seduko[][9]);
int sedukoScanNumber(int *row,int *col,int *num);
void sedukoInsertNumbers(int row,int col,int num);
void sedukoConstNumbers(int constarr[][9]);
int checkConstatntNumbers(int row,int col);
int sedukoEnd();
void red ();
void yellow();
void blue();
void whiteBlue();
void magenta();
void lightGreen();
void reset ();




#endif // SEDUKO_H_INCLUDED
