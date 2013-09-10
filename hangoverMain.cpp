#include "hangover.h"

bool readfile(char *nameStr, float *num)
{
	fstream inFile(nameStr);

	if(!inFile.is_open())
		return false;

	string str;
	int i=0;
	while(!inFile.eof())
	{ 			
		getline(inFile, str, '\n'); 
		num[i++] = atof(str.c_str());	
		if(num[i-1] == 0)
			break;
	}
	return true;
}

int main()
{
	//float input;
	/*while(1)
	{
		cin >> input;
		cout << calNum(input) << endl;
	}*/

	cout<< "===start==="<<endl;

	float *inNum = new float[10];
	char *str = "hangoverInput.txt";
	if(!readfile(str, inNum))
		cout << "file error!" << endl;
	else
	{
		int i = 0;
		while(inNum[i] != 0)
		{
			cout << calNum(inNum[i++]) << " card(s)" << endl;
		}
	}	
	cout<< "===end==="<<endl;

	system("pause");
    return 0;
}
