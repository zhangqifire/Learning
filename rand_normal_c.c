/*************************************************************************
 > File Name: rand_normal_c.c
 > Author: zhangqifire
 > Mail: 18810500641@163.com
 > Created Time: 三 10/29 20:01:08 2014
 ************************************************************************/
/*
 * 分别用三种方法产生随机数
 * 方法一：由均匀分布的随机数产生
 * 方法二：由Box－Muller方法产生随机数
 * 方法三：由正弦曲线图形得到（monte—carlo方法）
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define rd (rand()/(RAND_MAX+1.0))
#define pi 3.141592653
//重写rand函数产生min到max之间的均匀分布
template <class T>
T rand(T min, T max)
{
    return min+(max-min)*rand()/(RAND_MAX+1.0);
}
 //求均值为miu，方差为sigma的正太分布函数在x处的函数值
double normal(double x,double miu,double sigma)
{
	return 1.0/sqrt(2*pi)/sigma*exp(-1*(x-miu)*(x-miu)/(2*sigma*sigma));
}
//按照矩形区域在函数值曲线上下位置分布情况得到正太函数x值(monte-carlo 思想）
double randn(double miu,double sigma, double min ,double max)
{
	double x,y,dScope;
	do{
		x=rand(min,max);
	    y=normal(x,miu,sigma);
		dScope=rand(0.0,normal(miu,miu,sigma));
    }while(dScope>y);
    return x;
}
double randselect(int type)
{
	if(type==1)
        //方法一按照12个均匀分布之和减去6得到正态分布函数的x值
		return rd*12-6.0;
	else if(type==2)
        //方法二按照Box-muller计算公式y=sqrt(-2*ln(U))*cos(2*PI*V)计算得到x
		return sqrt(-2*log(rand()/(RAND_MAX+1.0)))*cos(2*pi*rand()/(RAND_MAX+1.0));
	else
        //方法3用位置分布得到x
		return randn(0.0,1.0,-10.0,10.0);
}
int main()
{
    srand((unsigned)time( NULL ));
    //将随机生成的数据分别保存到normal_method_1，normal_method_2，normal_method_3中
    FILE *fdata;
	fdata=fopen("/Users/zq/Desktop/normal_method_1","a");
    for (int i=0;i<1000000;i++)
    {
        fprintf(fdata,"%lf\n",randselect(1));
    }
    fdata=fopen("/Users/zq/Desktop/normal_method_2","a");
    for (int i=0;i<1000000;i++)
    {
        fprintf(fdata,"%lf\n",randselect(2));
    }
    fdata=fopen("/Users/zq/Desktop/normal_method_3","a");
    for (int i=0;i<1000000;i++)
    {
        fprintf(fdata,"%lf\n",randselect(3));
    }
    
    return 0;
}
