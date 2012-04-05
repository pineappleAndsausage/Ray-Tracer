#pragma once
#include <iostream>
#include "Vector3F.h"
#include "Colors.h"
#include "unittest.h"


using namespace std;
void vectorTest();



int main(int argc, char **argv)
{
	unittest(argc,argv);
	getchar();
	return 0;
}

void vectorTest()
{
	Vector3F vec(1,2,3);	
	Vector3F vec2(1,0,0);	
	cout << vec << endl;		
	cout << "[] : " << vec[0] << vec[1] << vec[2] << endl;
	cout << "dot : " << vec * vec << endl;
	cout << "cross : " << vec % vec2 << endl;
	cout << "magnitude_squared : " << vec.magnitude_squared() << endl;
	cout << "magnitude : " << vec.magnitude() << endl;
	cout << "normalize : " << vec.normalize() << endl;

}