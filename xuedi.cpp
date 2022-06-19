#include<stdio.h>
#include<math.h>
int main() {
	double a, b, c;
	double x1, x2;
	double t;
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF)
	{
		t = b * b - 4 * a * c;
		if (a == 0)
			printf("不是一元二次方程");
		else
		{
			if (t >= 0)
			{
				x1 = ((-1) * b + sqrt(t)) / (2*a);
				x2 = ((-1) * b - sqrt(t)) / (2*a);
				printf("%.2lf %.2lf\n", x1, x2);
			}
			else
			{
				x1 = (-1) * b / (2 * a);
				x2 = sqrt((-1) * t) / (2 * a);
				printf("%.2lf+%.2lfi %.2lf-%.2lfi", x1, x2, x1, x2);
			}
		}
	}
	return 0;
}
