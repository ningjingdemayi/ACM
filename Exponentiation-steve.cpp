#include "stdafx.h"
#include <vector>
#include <iostream>

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

char toChar(int val)
{
	return val + 48;
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
	int i;
	for(i = 0; i < v2.size(); i++)
	{
		int t1 = toInt(v1[v1.size() - i - 1]);
		int t2 = toInt(v2[v2.size() - i - 1]);
		int t = t1 + t2 + up;
		up = t >= 10 ? 1 : 0;
		v1[v1.size() - i - 1] = toChar(t % 10);
	}

	if(up) 
	{
		if(v1.size() > i)
			v1[v1.size() - i - 1] = toChar(toInt(v1[v1.size() - i - 1])+1);
		else
			v1 = "1" + v1; 
	}

	return v1;
}

string comput(string num, string num2)
{
	vector<number> calc;
	vector<string> result;
	string bits = "";

	vector<int> nums;
	long tmp;

	if(num.size() < num2.size())
	{
		bits = num;
		num = num2;
		num2 = bits;
		bits = "";
	}

	for(int i=0; i < num2.size(); i++)
	{
		nums.push_back(toInt(num2[i]));
	}

	while(num.size() >5)
	{
		calc.push_back(number(num.substr(0, 5)));
		num = num.substr(5,num.size());
	}
	calc.push_back(number(num.substr(0, num.size())));

	for(int p = nums.size() - 1; p >= 0; p-- )
	{
		for(int i = calc.size() - 1; i >= 0; i--)
		{
			char buffer[10];
			tmp = nums[p] * calc[i].numValue;
			if(tmp == 0) continue;
			_ltoa_s(tmp, buffer, 10, 10);
			result.push_back(string(buffer) + bits);
			bits += string(calc[i].length, '0');
		}

		bits = string(nums.size() - p, '0');
	}

	//Add results one by one.

	string finalRes = result[0];
	for(int i = 1; i < result.size(); i++)
	{
		finalRes = add(finalRes, result[i]);
	}

	return finalRes;
}

int Problem2()
{
	string numString;
	int times, dotpos;

	getline(cin,numString);

	times =	atoi(numString.substr(numString.find_first_of(' ', 0) + 1, numString.size()).c_str());
	numString = numString.substr(0, numString.find_first_of(' ', 0));
	dotpos =numString.size() - numString.find_first_of('.', 0) - 1;

	if(numString.find_first_of('.', 0) != string::npos)
		numString = numString.substr(0, numString.find_first_of('.', 0)) + numString.substr(numString.find_first_of('.', 0) + 1, numString.size());

	dotpos *= times;
	
	string res = numString;

	for(int i = 0; i< times -1 ; i++)
		res = comput(res, numString);
	
	res = res.substr(0, res.size() - dotpos) + "." + res.substr(res.size() - dotpos, res.size());

	cout << "final: " << res << endl;
    return 0;
}