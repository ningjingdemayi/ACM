#include "twoDataMul.h"

int main()
{
	cout << "==" << endl;

	string a = "10000";
	string b = "789";
	int powerFig = 3;
	string c;

	/*c = dataAdd(a, b);

	cout << a.c_str() << " + " << b.c_str() << " = " << endl;
	cout << c.c_str() << endl << "==" << endl;*/

	/*c = dataMul(a, b);

	cout << a.c_str() << " * " << b.c_str() << " = " << endl;
	cout << c.c_str() << endl << "==" << endl;*/

	c = dataPower(a, powerFig);

	cout << a.c_str() << "^" << powerFig << " = " << endl;
	cout << c.c_str() << endl << "==" << endl;


	return 1;
}
