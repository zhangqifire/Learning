/*************************************************************************
    > File Name: Calculate_PI.c
    > Author: zhangqifire
    > Mail: 18810500641@163.com 
    > Created Time: 三 10/29 19:33:13 2014
 ************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
/*
 *  利用蒙特卡罗方法计算圆周率，通过投针实验的n次模拟，计算出在边长为1的正方形中，点坐在半径为1的圆中的概率。
*/
double Cal_Pi(const long n)
{
	srand(time(NULL));
	long sum=0;
	double x=0.0,y=0.0;
	for(long i=0;i<n;i++)
	{
		 x = (double)(rand())/(double)RAND_MAX;
		 y = (double)(rand())/(double)RAND_MAX;
		 if(pow(x,2)+pow(y,2)<=1)
		 {
			 sum++;
		 }
	}
	return 4.0*((double)sum/(double)n);
}
int main()
{
	long n=0;
	printf("请输入模拟次数:\n");
	scanf("%ld",&n);
	if(n<0)
	{
		printf("输入错误\n");
		exit(1);
	}
	double pi=Cal_Pi(n);
	printf("模拟了%ld次\n圆周率pi=%lf\n",n,pi);
	return 0;
}
