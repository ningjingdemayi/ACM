#include "stdafx.h"
#include <boost/algorithm/string.hpp> 
#include <boost/unordered_map.hpp> 
#include <boost/any.hpp> 
#include <locale> 

#include <vector>
#include <iostream>
#include "utilities.h"

using namespace boost;
using namespace std;

typedef boost::unordered_map<int, vector<string>> _map; 

struct CharacterTable
{
public:
	_map map;

	CharacterTable()
	{
		vector<string> str;
		str.push_back("A");
		str.push_back("B");
		str.push_back("C");
		map.insert(_map::value_type(2, str));
		str.clear();
		str.push_back("D");
		str.push_back("E");
		str.push_back("F");
		map.insert(_map::value_type(3, str));
		str.clear();
		str.push_back("G");
		str.push_back("H");
		str.push_back("I");
		map.insert(_map::value_type(4, str));
		str.clear();
		str.push_back("J");
		str.push_back("K");
		str.push_back("L");
		map.insert(_map::value_type(5, str));
		str.clear();
		str.push_back("M");
		str.push_back("N");
		str.push_back("O");
		map.insert(_map::value_type(6, str));
		str.clear();
		str.push_back("P");
		str.push_back("S");
		str.push_back("R");
		map.insert(_map::value_type(7, str));
		str.clear();
		str.push_back("V");
		str.push_back("T");
		str.push_back("U");
		map.insert(_map::value_type(8, str));
		str.clear();
		str.push_back("W");
		str.push_back("X");
		str.push_back("Y");
		map.insert(_map::value_type(9, str));
	}

	int find(char v)
	{
		string str(&v);

		for (_map::iterator it = map.begin(); it != map.end(); ++it) 
			for (vector<string>::iterator p =it->second.begin(); p != it->second.end(); p++) 
				if(*p == str) return it->first;

		return 0;
	}
}table;

int Problem3()
{
	string numString = "ITS-EASY";
	int times;
	vector<string> col;
	vector<int> count;

	getline(cin,numString);

	times = atoi(numString.c_str());

	for(int i = 0; i< times; i++)
	{
		getline(cin,numString);
		algorithm::erase_all(numString, "-");
		for(int i = 0; i < numString.size(); i++)
		{
			if(!isdigit(numString[i]))
				numString[i] = toChar(table.find(numString[i]));
		}
		col.push_back(numString);
	}
	
	for(int i = 0; i< col.size(); i++)
		for(int j = i+1; j< col.size(); j++)
			if(col[i] == col[j])
				count[i]++;

	//algorithm::iter_split(strCollection, numString, first_finder(" "));
	
	return 0;
}