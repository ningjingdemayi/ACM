#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct number
{
	string strValue;
	long numValue;
	int length;

	number(string v1)
	{
		strValue = v1;
		numValue = atol(strValue.c_str());
		length = v1.size();
	}
};

int toInt(char val)
{
	return val - 48;
}

string add(string v1, string v2)
{
	string t;
	if(v1.size() < v2.size())
	{
		t = v1;
		v1 = v2;
		v2 = t;
	}

	int up = 0;
	int i = 0;
	for(i ; i< v1.size(), i<=v2.size(); i++)
	{
		int t1 = toInt(v1[i]);
		int t2 = toInt(v2[i]);
		int t = t1 + t2 + up;
		up = t > 10 ? 1 : 0;
		v1[i] = t % 10;
	}

	if(up) v1[i] = toInt(v1[i])+1;

	return v1;
}

void comput(string *num)
{
	vector<number> calc;
	vector<string> result;
	string bits = "";

	vector<int> nums;
	long tmp;

	for(int i=0; i < (*num).size(); i++)
	{
		nums.push_back(toInt((*num)[i]));
	}

	while((*num).size() >5)
	{
		calc.push_back(number((*num).substr(0, 5)));
		*num = (*num).substr(5,(*num).size());
	}
	calc.push_back(number((*num).substr(0, (*num).size())));

	for(auto p = nums.end(); p != nums.begin(); p-- )
	{
		for(int i = 0; i< calc.size(); i++)
		{
			char buffer[10];
			tmp = (*p) * calc[i].numValue;
			_ltoa_s(tmp, buffer, 10, 10);
			result.push_back(string(buffer) + bits);
			bits += string(calc[i].length, '0');
		}

		bits = "";
	}

	//Add results one by one.

	string finalRes = result[0];
	for(int i = 1; i < calc.size(); i++)
	{
		finalRes = add(finalRes, result[i]);
	}
}

int Problem2()
{
	string numString;
	int times, dotpos;

	//getline(cin,numString);

	numString = "1.01234 3";

	times =	atoi(numString.substr(numString.find_first_of(' ', 0) + 1, numString.size()).c_str());
	numString = numString.substr(0, numString.find_first_of(' ', 0));
	dotpos =numString.size() - numString.find_first_of('.', 0) - 1;

	if(numString.find_first_of('.', 0) != string::npos)
		numString = numString.substr(0, numString.find_first_of('.', 0)) + numString.substr(numString.find_first_of('.', 0) + 1, numString.size());

	dotpos *= times;
	
	for(int i = 0; i< times ; i++)
		comput(&numString);
	
    return 0;
}