#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>

int main()
{
	int n, op = 1;
	while (op != 0)
	{
		double arr[100] = { 0 };
		printf("����������ܸ�����\n");
		scanf("%d", &n);
		printf("���������������\n");
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
		printf("A�಻ȷ�����ǣ�%lf\n", ua);
		printf("��������������ޣ�ע�ⵥλ�ͱ�������һ�£���\n");
		double ub = 0, delta = 0, u = 0;
		scanf("%lf", &delta);
		ub = delta / sqrt(3);
		printf("B�಻ȷ�����ǣ�%lf\n", ub);
		u = sqrt(ua * ua + ub * ub);
		printf("�ϳɲ�ȷ�����ǣ�%lf\n����0����������1����\n", u);
		scanf("%d", &op);
	}
	return 0;
}