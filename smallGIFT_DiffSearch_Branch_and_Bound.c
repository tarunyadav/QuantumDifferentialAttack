// Practical-Quantum_Differential_Trail_Search_Classical.cpp : Defines the entry point for the console application.
//#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

//FILE *fout1;

double counterr[256];

unsigned int D[16][16]={16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 2,
						0, 0, 0, 0, 0, 4, 4, 0, 0, 2, 2, 0, 0, 2, 2, 0,
						0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 0, 2, 2, 2, 2, 2,
						0, 0, 0, 2, 0, 4, 0, 6, 0, 2, 0, 0, 0, 2, 0, 0,
						0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 2, 2, 4,
						0, 0, 4, 6, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0,
						0, 0, 2, 0, 0, 2, 0, 0, 2, 2, 2, 4, 2, 0, 0, 0,
						0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4,
						0, 2, 0, 2, 0, 0, 2, 2, 2, 0, 2, 0, 2, 2, 0, 0,
						0, 4, 0, 0, 0, 0, 4, 0, 0, 2, 2, 0, 0, 2, 2, 0,
						0, 2, 0, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 0, 2, 0,
						0, 0, 4, 0, 4, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0,
						0, 2, 2, 0, 4, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 2,
						0, 4, 0, 0, 4, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0,
						0, 2, 2, 0, 4, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 2};//S-box DDT

unsigned int pbox[8] ={ 0,3,5,7,2,4,6,1};//Permutation BP
	
double cc,cc1;
unsigned int inR1[2],inR2[2],inR3[2],inR4[2];
unsigned int sbcnt1,sbcnt2,sbcnt3,sbcnt4;
float sbcnt1p,sbcnt2p,sbcnt3p;


void R3()
{//1
	unsigned int a1,a2;
	unsigned int z1,z2;
	unsigned int i1,i2;
	unsigned int p1,p2;	
	unsigned int temp1=0, temp2=0, temp3=0;
	sbcnt3=0; sbcnt3p=0;
	float A=0,B=0;
	temp1=inR3[0];
	
	a1=  (temp1 & 0xf0)>>4;
	a2=  (temp1 & 0x0f);

	if(a1!=0){sbcnt3++; z1=16;} else z1=1;
	if(a2!=0){sbcnt3++; z2=16;} else z2=1;

	for(i1=0;i1<z1;i1++)
	for(i2=0;i2<z2;i2++)
	{
		p1=D[a1][i1];
		if(p1==0)continue;

		p2=D[a2][i2];
		if(p2==0)continue;

		if((p1==2||p1==4||p1==6||p1==16) && (p2==2||p2==4||p2==6||p2==16))
		{//3
			if(p1==2)A=A+3;if(p1==4)A=A+2;if(p1==6)A=A+1.4;   if(p2==2)A=A+3;if(p2==4)A=A+2;if(p2==6)A=A+1.4;
			sbcnt3p=A;
	
			temp3= (i1<<4 | i2) ;

			int round=0,x=0,out=0;
	
			for(round=0; round<8;round++)
			{
				x = (temp3>>round)&0x1;
				out= out|(x << pbox[round]);
			}
			

			inR4[0]=out;

			for(int m=1;m<256;m++)
			{	
			  if(inR4[0]==m)
			  {
			
				cc= sbcnt1p+sbcnt2p+sbcnt3p;
				counterr[m]= counterr[m]+pow(2,-cc);
			  }
			}
			 	
		}
		A=0;
	
     }
}//1

void R2()
{//1
	unsigned int a1,a2;
	unsigned int z1,z2;
	unsigned int i1,i2;
	unsigned int p1,p2;	
	unsigned int temp1=0, temp2=0, temp3=0;
	sbcnt2=0; sbcnt2p=0;
	float A=0,B=0;
	temp1=inR2[0];
	
	a1=  (temp1 & 0xf0)>>4;
	a2=  (temp1 & 0x0f);

	if(a1!=0){sbcnt2++; z1=16;} else z1=1;
	if(a2!=0){sbcnt2++; z2=16;} else z2=1;

	for(i1=0;i1<z1;i1++)
	for(i2=0;i2<z2;i2++)
	{//counter1=0;
		p1=D[a1][i1];
		if(p1==0)continue;

		p2=D[a2][i2];
		if(p2==0)continue;

		if((p1==2||p1==4||p1==6||p1==16) && (p2==2||p2==4||p2==6||p2==16))
		{//3
			if(p1==2)A=A+3;if(p1==4)A=A+2;if(p1==6)A=A+1.4;   if(p2==2)A=A+3;if(p2==4)A=A+2;if(p2==6)A=A+1.4;
			sbcnt2p=A;

			temp3= (i1<<4 | i2) ;

			int round=0,x=0,out=0;

			for(round=0; round<8;round++)
			{
				x = (temp3>>round)&0x1;
				out= out|(x << pbox[round]);
			}
			

			inR3[0]=out;

			R3();
	
		}
		A=0;
	
     }
}//1

void R1()
{//1
	unsigned int a1,a2;
	unsigned int z1,z2;
	unsigned int i1,i2;
	unsigned int p1,p2;	
	unsigned int temp1=0, temp2=0, temp3=0;
	sbcnt1=0; sbcnt1p=0;
	
	float A=0,B=0;

	temp1=inR1[0];
	
	a1=  (temp1 & 0xf0)>>4;
	a2=  (temp1 & 0x0f);

	if(a1!=0){sbcnt1++; z1=16;} else z1=1;
	if(a2!=0){sbcnt1++; z2=16;} else z2=1;

	for(i1=0;i1<z1;i1++)
	for(i2=0;i2<z2;i2++)
	{//counter1=0;
		p1=D[a1][i1];
		if(p1==0)continue;

		p2=D[a2][i2];
		if(p2==0)continue;

		if((p1==2||p1==4||p1==6||p1==16) && (p2==2||p2==4||p2==6||p2==16))
		{//3
			if(p1==2)A=A+3;if(p1==4)A=A+2;if(p1==6)A=A+1.4;   if(p2==2)A=A+3;if(p2==4)A=A+2;if(p2==6)A=A+1.4;
			sbcnt1p=A;

			temp3= (i1<<4 | i2) ;
			int round=0,x=0,out=0;
	
			for(round=0; round<8;round++)
			{
				x = (temp3>>round)&0x1;
				out= out|(x << pbox[round]);
			}
			
			inR2[0]=out;

			R2();
	
		}
		A=0;
	
     }
}//1

//Main function
int main()
{
	int i,j;

	//fout1=fopen("smallGIFT_DiffSearch_3R_Branch_and_Bound_Output.txt","a+");

	for(i=1;i<256;i++)
		counterr[i]=0;

	//Input Difference
	inR1[0]=0x01;

	R1();

	for(j=1;j<256;j++)
		printf("%d: %lf, ", j, counterr[j]);
		//fprintf(fout1,"%d: %lf, ", j, counterr[j]);

	
}
