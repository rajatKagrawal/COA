#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long int strBin(char bn[]);
void Display();
void decode(long long int bin);
void simulate(FILE *bn);
void read(FILE *bn);


int pc;
long long int ir;
int reg[15]={0};
int Label[10];

void main(){
	char fName[20];
	FILE *bn;
	int choice;

	printf("Enter Binary file name\n");
	scanf("%s",fName);
	while(1){
		bn=fopen(fName,"r+");
		printf("Select an option from below\n");
		printf("1>System\n");
		printf("2>Display Instructioons\n");
		printf("0>exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			simulate(bn);
		}
		else if(choice==2)
			read(bn);
		else if(choice==0)
			break;
		else
			printf("wrong instructions\n");
		fclose(bn);
	}
}

/*Displaying values in register*/

void Display()
{
	int i;
	printf("General purpose registers\n");
	for(i=0;i<15;i++)
	{
		printf("R%d:%d	",i,reg[i]);
		if((i+1)%5==0)
			printf("\n");
	}
	printf("value of special registers\n");
	printf("Program Counter: %d	",pc);
	printf("Instruction Register: %lld\n",ir);
	printf("\n");
	
}


/*convert string to binary*/

long long int strBin(char bn[])
{
	long long int i,bin=0;
	for(i=0;i<=15;i++)
	{
		if(bn[i]=='1')
		{
			bin=(bin*10)+1;
			//printf("%ld\n",bin);
			
		}
		else
		{
			bin=bin*10;
			//printf("%ld\n",bin);
		}
	}
	//printf("%d\n",bin);
	return bin;
}

/*	thios function will decode the instruction in IR	*/

void decode(long long int bin)
{

}

/*
	following is the main simulator of functions
*/

void simulate(FILE *bn)
{
	int i;
	int c=0;
	long long int bin;
	char temp[20];
	while(1)
	{
		 i=fscanf(bn,"%s\n",temp);
                if(i==-1)
                break;
		//printf("%s\n",temp);
		bin=strBin(temp);
		printf("%lld\n",bin);
		//printf("%lld	%d\n",x,length(x));
		ir=bin;
		
		c=c+1;
		pc=c;
		Display();
	}
	printf("\n");
	//Display();
}


/*
	the following function is to read and diplay binary instructions
*/
void read(FILE *bn)
{
	int i;
	char temp[20];
	while(1)
	{
		i=fscanf(bn,"%s'\n",temp);
		if(i==-1)
		break;
		printf("%s\n",temp);	
	}
	printf("\n");
}
