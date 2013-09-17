#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

const float pi = 3.1415926;

float Comput(int year)
{
	float area = year * 50;

	return pow(area / pi, 0.5);
}

int Problem5()
{
	string len,_x,_y;
	getline(cin, len);

	int nums = atoi(len.c_str());
	float t = 0.0,x,y,radius;

	for(int i = 1; i <= nums ;i++)
	{
		getline(cin, len);
		stringstream ss(len);
		
		getline(ss, _x, ' ');
		getline(ss, _y);

		x = atof(_x.c_str());
		y = atof(_y.c_str());
		radius = pow( (pow(x,2) + pow(y,2)) , 0.5 );

		for (int j = 1; ;j++)
		{
			if(Comput(j) > radius)
				cout << "Property " << i << ": This property will begin eroding in year ." << j << "."<< endl;
		}
	}

	return 0;
}