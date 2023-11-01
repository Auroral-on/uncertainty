#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#define max 100
double arr[max] = { 0 };
int op = 1;

/*
操作标识：0：退出程序
			1：普通不确定度计算


*/
void calculate(int n,double* arr)
{
	double dx = 0, ua = 0, p = 0;
	for (int i = 0; i < n; i++)
	{
		p += arr[i];
	}
	p /= n;
	for (int i = 0; i < n; i++)
	{
		dx += (arr[i] - p) * (arr[i] - p);
	}
	dx = dx / n;
	dx = dx / (n - 1);
	ua = sqrt(dx);
	printf("A类不确定度是：%lf\n", ua);
	printf("请输入仪器误差限（注意单位和变量保持一致）：\n");
	double ub = 0, delta = 0, u = 0;
	scanf("%lf", &delta);
	ub = delta / sqrt(3);
	printf("B类不确定度是：%lf\n", ub);
	u = sqrt(ua * ua + ub * ub);
	printf("合成不确定度是：%lf\n相对不确定度是：%lf\n", u, u / p);
	return;
}


void normal()
{
	int n;
	printf("请输入变量总个数：\n");
	scanf("%d", &n);
	if (n > 100)
	{
		printf("目前不支持%d以上的变量个数\n", max);
		return;
	}
	printf("请依次输入变量：\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &arr[i]);
	}
	calculate(n, arr);
	return;
}

void linear_regression()
{
	int n;
	double x[max], y[max];
	double x_bar = 0, x2_bar = 0, y_bar = 0, y2_bar = 0, r = 0, xy_bar = 0, oy = 0;
	double a = 0, b = 0;
	double ua_a = 0, ub_a = 0, ua_b = 0, ub_b = 0, u_a = 0, u_b = 0;
	printf("请输入测量总次数：\n");
	scanf("%d", &n);
	if (n > 100)
	{
		printf("目前不支持%d以上的变量个数\n", max);
		return;
	}
	printf("请依次输入自变量：\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
	}
	printf("请依次输入因变量：\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		x_bar += x[i];
		x2_bar += x[i]*x[i];
		y_bar += y[i];
		y2_bar += y[i]*y[i];
		xy_bar += x[i] * y[i];
	}
	x_bar /= n;
	x2_bar /=n;
	y_bar /=n;
	y2_bar /=n;
	xy_bar /=n;
	b = (x_bar * y_bar - xy_bar) / (x_bar * x_bar - x2_bar);
	a = y_bar - b * x_bar;
	r = (xy_bar - x_bar * y_bar) / sqrt((x2_bar - x_bar * x_bar) * (y2_bar - y_bar * y_bar));
	printf("y=bx+a\nb=%lf,a=%lf,r=%lf\n", b, a, r);
	printf("请依次输入y的测量误差属性（0为标准测量误差，1为给定标准差，2为有限次测量标准偏差）：\n");
	int opy = 0;
	scanf("%d", &opy);
	switch (opy)
	{
		case 0:
		{
			printf("请输入仪器误差限（注意单位和变量保持一致）：\n");
			double delta = 0;
			scanf("%lf", &delta);
			oy = delta / sqrt(3);
			break;
		}
		case 1:
		{
			printf("请输入标准差（注意单位和变量保持一致）：\n");
			scanf("%lf", &oy);
			break;
		}
		case 2:
		{
			double oyi = 0;
			for (int i = 0; i < n; i++)
			{
				oyi += (y[i] - a - b * x[i]) * (y[i] - a - b * x[i]);
			}
			oy = sqrt(oyi / (n - 2));
			break;
		}
		default:printf("wrong operation!"); break;
	}
	double k = (double)n;
	double temp1 = 1 / (k - 2);
	double temp2 = 1 / (r * r);
	ua_b = fabs(b*sqrt(temp1 * (temp2 - 1)));
	ua_a = ua_b * sqrt(x2_bar);
	ub_b = oy * sqrt(1 / (k * (x2_bar - x_bar * x_bar)));
	ub_a = ub_b * sqrt(x2_bar);
	u_a = sqrt(ua_a * ua_a + ub_a * ub_a);
	u_b = sqrt(ua_b * ua_b + ub_b * ub_b);
	printf("b的A类不确定度是：%lf\nb的B类不确定度是：%lf\nb的合成不确定度是：%lf\na的A类不确定度是：%lf\na的B类不确定度是：%lf\na的合成不确定度是：%lf\n", ua_b, ub_b, u_b, ua_a, ub_a, u_a);
}

int main()
{
	while (1)
	{
		printf("请输入操作（操作标识见注释）：\n");
		scanf("%d", &op);
		switch (op)
		{
			case 0:
				printf("祝你基物实验顺利！");
				return 0;
			case 1:
			{
				normal(); 
				break;
			}
			case 2:
			{
				linear_regression();
				break;
			}
			default:break;
		}
	}
	return 0;
}


/*测试数据
1.22338
1.60066
2.01072
2.42176
2.82374
3.22131
3.6189
4.03528
4.43941
4.82062

28.7
38.7
48.7
58.7
68.7
78.7
88.7
98.7
108.7
118.7


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20

8.330
8.052
7.805
7.562
7.344
7.105
6.865
6.648
6.408
6.115
5.955
5.705
5.445
5.215
5.005
4.752
4.526
4.265
4.045
3.815
*/
