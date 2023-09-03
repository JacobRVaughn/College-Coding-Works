#include <string>
#include <iostream>
using namespace std;

int myabs(int value) {
	cout << "integer\n";
	if (value < 0) {
		value = -value;
	}
	return value;
}

double myabs(double value) {
	cout << "double\n";
	if (value < 0) {
			value = -value;
	}
	return value;
}


int main(int argc, char **argv) {

	string strValue;
	double dblValue;

	cout << "Enter a number to retrieve the absolute value for:  \n";
	cin >> dblValue;

	if(dblValue == (int)dblValue) {
	  cout << "whole\n";
	  cout << myabs((int) dblValue);
	} else {
	  cout << "decimal\n";
	  cout << myabs(dblValue);
	}

	/*

	int fn = -40;
	unsigned long total = fn;
	string strFn =  "The factorial number for " + to_string(fn) +  " is ";

	if (fn >= 0) {
	  while (fn > 0) {
//		strFn += to_string(fn);
	 	if (fn > 1) {
    		total = total * (fn - 1);
//	    	strFn += " * ";
	    }
	    fn -= 1;
	  }
	  cout << strFn << " = " << total << endl;
	} else {
		cout << fn << " is a negative number and does not have a Factorial";
	}

*/
	return 0;
}
