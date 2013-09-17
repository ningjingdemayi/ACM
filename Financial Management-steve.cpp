#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int Problem4()
{
	string len;
	getline(cin, len);

	int nums = atoi(len.c_str());
	float t = 0.0;

	for (int i = 0; i< nums ;i++)
	{
		getline(cin, len);

		t += atof(len.c_str());
	}

	cout << "value is " << t / nums << endl;
	return 0;
}