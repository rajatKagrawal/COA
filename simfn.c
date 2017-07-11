#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long int strBin(char bn[]);
int binInt(int bin);
void Display();
void decode(long long int bin);
void simulate(FILE *bn);
void read(FILE *bn);
int length(long long int);
void symbol(char fName[]);


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
	symbol(fName);
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

/*converting binary to integer*/

int binInt(int n)
{
	int i,bin=0,c=1;
	for(i=n;i>0;i=i/10)
	{
		bin=bin+(i%10)*c;
		c=c*2;
	}
	return bin;
}


/* managing symbols*/

void symbol(char fName[])
{
	FILE *fp,*bn;
	char temp[20];
	int i,k,c=0;
	long long int bin;
	fp=fopen("temp.dat","w+");
	bn=fopen(fName,"r+");
	while(1){
		
		 i=fscanf(bn,"%s\n",temp);
                if(i==-1)
                break;
		//printf("%s\n",temp);
		bin=strBin(temp);
		if(length(bin)==16)
		{
			k=bin/(pow(10,8));
			if(k==11100111)
			{
				Label[binInt(bin%1000)]=c;
				continue;
			}
			
		}
		c++;
		fprintf(fp,"%s\n",temp);
		//printf("%lld\n",bin);
		//printf("%lld	%d\n",x,length(x));
		//ir=bin;
		
		//c=c+1;
		//pc=c;
	}
	
	fclose(fp);
	fclose(bn);
	remove(fName);
	rename("temp.dat",fName);
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
		//if(i<10)
			//printf("L[%d]=%d \n",i,Label[i]);
	}
	printf("value of special registers\n");
	printf("Program Counter: %d	",pc);
	printf("Instruction Register: %lld\n",ir);
	printf("\n");
	
}

/*instruction will compute length
	of the binary number
*/

int length(long long int bin){
	int l=0;
	for(;bin>0;bin=bin/10)
	{
		l++;
	}
return l;
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
	int i,k;
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
