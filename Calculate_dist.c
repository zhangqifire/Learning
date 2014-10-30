/*************************************************************************
    > File Name: Calculate_dist.c
    > Author: zhangqifire
    > Mail: 18810500641@163.com 
    > Created Time: 四 10/30 13:45:29 2014
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
//计算方法一的密度分布
#ifndef Method_1
#define Method_1
#define datafilein "normal_method_1"
#define datafileout "normal_method_1_dist"
#endif

//计算方法二的密度分布
//#ifndef Method_2
//#define Method_2
//#define datafilein "normal_method_2"
//#define datafileout "normal_method_2_dist"
//#endif
//计算方法三的密度分布
//#ifndef
//#defint Method_3
//#define datafilein "normal_method_3"
//#define datafileout "normal_method_3_dist"
//#endif
int main()
{

	FILE *finput,*foutput;
	int i, N=1000000, m=100;
	double max=5, min=-5, d, x;
	d=(max-min)/m;
	
	int count[m], flag;
	for(i=0;i<m;i++)  count[i]=0;
	//读取datafilein文件输入内容
	finput=fopen(datafilein,"r");
	
	for(i=0;i<N;i++)
	{
		fscanf(finput,"%lf",&x);
		flag=(x-min)/d;
		if(flag==m) count[m-1]++;
		else count[flag]++;
	}
	fclose(finput);
	
	float p[m];
	for(i=0;i<m;i++)  p[i]=(float)count[i]/N;
	//打开文件datafileout，把输出结果存入文件中
	foutput=fopen(datafileout,"w");
	for(i=0;i<m;i++)
	{
		fprintf(foutput,"%f\t%f\n",min+(1/2+i)*d,p[i]);
	}
	fclose(foutput);
   	return 0;

}
