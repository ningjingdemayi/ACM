#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int toInt(char val)
{
	return val - 48;
}

void comput(string *num)
{
	vector<long> calc;
	vector<int> nums;
	long tmp;

	for(int i=0; i < (*num).size(); i++)
	{
		nums.push_back(toInt((*num)[i]));
	}

	while((*num).size() >5)
	{
		calc.push_back(atol((*num).substr(0, 5).c_str()));
		*num = (*num).substr(5,(*num).size());
	}
	calc.push_back(atol((*num).substr(0, (*num).size()).c_str()));

	for(auto p = nums.end(); p != nums.begin(); p-- )
	{
		for(int i = 0; i< calc.size(); i++)
		{
			tmp = (*p) * calc[i];
			// calc continue.
		}
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