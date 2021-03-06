#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#define clk CLOCKS_PER_SEC
using namespace std;
int maximum(int *max)
{
	int val=0;
	for (int i=0;i<9;i++)
	{
		if (max[i]>val)
			val=max[i];
	}
	return val;
}
void dilation(int **a,int h,int b)
{
    int i,j;
    for(i=1;i<b-1;i++)
    {
        for(j=1;j<h-1;j++)
		{
			int max[9] = { a[i-1][j-1], a[i+1][j+1], a[i-1][j], a[i+1][j], a[i][j-1], a[i][j+1], a[i][j], a[i-1][j+1], a[i+1][j-1] };
			a[i][j]=maximum(max);
		}
    }
}
int main()
{
	ifstream fin;
	fin.open("input.in");
	ofstream fout;
	fout.open("output.dat");
    int h,b,i,j,cs,k;
	double total=0,total1=0;
	fin>>cs;
	for (k=1;k<=cs;k++)
	{
		clock_t st = clock();
		fin>>h>>b;
		int** a=new int*[b];
		for(i=0;i<b;i++)
	        a[i]=new int[h];
	    for(i=0;i<b;i++)
	    {
			for(j=0;j<h;j++)
	            fin>>a[i][j];
	    }
		clock_t st1 = clock();
	    dilation(a,h,b);
		clock_t et = clock();
		double t=double(et - st)/CLOCKS_PER_SEC;
		double t1=double(et - st1)/CLOCKS_PER_SEC;
		total+=t;
		total1+=t1;
		fout<<k<<'\t'<<h<<'\t'<<b<<'\t'<<h*b<<'\t'<<t<<'\t'<<t1<<endl;
	}
	fin.close();
	//fout<<total<<' '<<total1;
	fout.close();
	return 0;
}