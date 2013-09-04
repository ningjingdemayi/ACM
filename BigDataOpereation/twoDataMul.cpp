#include "twoDataMul.h"

string dataMul(const string mulA, const string mulB)
{
	string tmpMulStr="", mulOut = "abc";

	int tmpA, tmpB, mulSignleBit, carryBit;
	int lenA, lenB;

	lenA = mulA.length();
	lenB = mulB.length();
	
	for(int i = lenB-1; i >=0; i--)		
	{
		mulSignleBit = mulB[i] - '0';

		carryBit = 0;
		tmpMulStr = "";

		for(int j = 0; j <= (lenA/5); j++)
		{
			int startBit = lenA - 5*(j+1);		

			if(startBit > 0)
				tmpA = atoi(mulA.substr(startBit, 5).c_str());
			else
			{
				int leftLen = lenA - 5*j;
				tmpA = atoi(mulA.substr(0, leftLen).c_str());
			}
				
			int tmpMul;

			tmpMul = tmpA * mulSignleBit + carryBit;

			carryBit = tmpMul / (int)1e5;

			char *mulBuff = new char[5];
			itoa((tmpMul % (int)1e5), mulBuff, 10);
			tmpMulStr = tmpMulStr.insert(0, mulBuff, 0, 5);			
		}
		tmpMulStr = tmpMulStr.append((lenB-1-i), '0');
		mulOut = dataAdd(tmpMulStr, mulOut);
	}
	return mulOut;
}

string dataAdd(const string addA, const string addB)
{
	string addOut = "";

	int tmpA, tmpB, tmpSum;
	int lenA, lenB, maxLen;
	
	int carryBit = 0; // carry bit - [0, 1]

	lenA = addA.length();
	lenB = addB.length();

	maxLen = (lenA > lenB) ? lenA : lenB;

	for(int i=0; i <= (maxLen/5); i++)
	{
		// get 5bit of A
		int startBitA = lenA - 5*(i+1);
		
		if(startBitA >= 0)
			tmpA = atoi(addA.substr(startBitA, 5).c_str());
		else
		{
			int leftLenA = lenA - 5*i;
			if(leftLenA < 0)
				tmpA = 0;
			else
				tmpA = atoi(addA.substr(0, leftLenA).c_str());
		}

		// get 5bit of B
		int startBitB = lenB - 5*(i+1);
	
		if(startBitB >= 0)
			tmpB = atoi(addB.substr(startBitB, 5).c_str());
		else
		{
			int leftLenB = lenB - 5*i;
			if(leftLenB < 0)
				tmpB = 0;
			else
				tmpB = atoi(addB.substr(0, leftLenB).c_str());
		}

		// cal 5bit sum
		if(tmpA == 0 && tmpB == 0 )
		{
			 if(i == (maxLen/5))
				 break;
			 else
				 ;//==bug


		}
		else
		{			
			tmpSum = tmpA + tmpB + carryBit;

			// cal carry bit
			if(tmpSum >= 1e5)
				carryBit = tmpSum / (int)1e5;
			else
				carryBit = 0;
		}

		// fill add string
		char *sumBuff = new char[5];
		string tmpSum5;
		itoa((tmpSum % (int)1e5), sumBuff, 10);
		tmpSum5.assign(sumBuff);

		if(tmpSum5.length() < 5 && i != (maxLen/5) )
			tmpSum5.insert(0, (5 - tmpSum5.length()), '0');

		addOut = addOut.insert(0, tmpSum5, 0, 5);
	}

	return addOut;
}

string dataPower(const string powerA,const int powerFig)
{
	string powerOut="1";

	for(int i = 0; i < powerFig; i++)
	{
		powerOut = dataMul(powerOut, powerA);
	}

	return powerOut;
}

