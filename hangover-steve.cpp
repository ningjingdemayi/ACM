#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int Problem3()
{
	string len;
	getline(cin, len);

	float val = atof(len.c_str());
	float t = 0.0;

	for (int i = 2; ;i++)
	{
		t += 1. / i;
		if (t >= val)
			break;
	}

	cout << "value is " << t - 2 << endl;
	return 0;
}