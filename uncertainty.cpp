#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>

int main()
{
	int n, op = 1;
	while (op != 0)
	{
		double arr[100] = { 0 };
		printf("请输入变量总个数：\n");
		scanf("%d", &n);
		printf("请依次输入变量：\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &arr[i]);
		}
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
		printf("合成不确定度是：%lf\n输入0结束，输入1继续\n", u);
		scanf("%d", &op);
	}
	return 0;
}