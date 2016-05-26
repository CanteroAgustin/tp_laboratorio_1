#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//print library
void printMenu();
void printSubMenuModificar();

//imput library.
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getStringNumber(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getAlNum(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getAlNumPunctSpace(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getAllString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

#endif // FUNCIONES_H_INCLUDED
