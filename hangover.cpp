#include "hangover.h"

int calNum(float maxLen)
{
	int n = 2;
	/*//欧拉公式在n小时的时候相当不靠谱啊
	while(oula(n) < maxLen)
	{
		n++;
	}*/

	float sum = 0;
	while(sum < maxLen)
	{
		sum += 1.0 / (n++);
	}
	return (n-2);
}

float oula(int n)
{
	float sum;

	sum = 0.5772 + log((float)n) - 1;
	
	return sum;
}
