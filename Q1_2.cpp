//#define _CRT_SECURE_NO_WARNINGS
//#define PI 3.141592465
//#include <iostream>
//#include <cmath>
//using namespace std;
//
///* Area formulas*/
//// Triangle:	S = (a*b)/2
//// Trapeze:		S = (a+b)*h/2
//// Circle:		S = PI*R^2
//// Ring:		S = PI*((R^2)-(r^2))
//
//// Function declaration block
//float area(int a, int b);
//float area(int a, int b, int h);
//float area(float R);
//float area(float R, float r);
//
//void main()
//{
//	// Variables
//	int a;
//	int b;
//	int h;
//	float R;
//	float r;
//	float result;
//
//	// Triangle block
//	cout << "Enter two side of a right triangle: ";
//	cin >> a >> b;
//	cout << "Area: " << area(a, b) << endl << endl;
//
//	// Trapeze block
//	cout << "Enter two bases and a hight of a trapeze" << endl;
//	cout << "Correct order: upper base, lower base, hight: ";
//	cin >> a >> b >> h;
//	cout << "Area: " << area(a, b, h) << endl << endl;
//
//	// Circle block
//	cout << "Enter a radius for a circle: ";
//	cin >> R;
//	cout << "Area: " << area(R) << endl << endl;
//
//	// Ring block
//	cout << "Enter two radiuses for a ring" << endl;
//	cout << "Correct order: outer radius, inner radius: ";
//	cin >> R >> r;
//	cout << "Area: " << area(R, r) << endl << endl;
//}
//
//// Triangle area function
//float area(int a, int b)
//{
//	return ((float)a * (float)b) / 2;
//}
//
//// Trapeze area function
//float area(int a, int b, int h)
//{
//	return ((float)a + (float)b) * h / 2;
//}
//
//// Circle area function
//float area(float R)
//{
//	return PI * (float)pow(R, 2);
//}
//
//// Ring area function
//float area(float R, float r)
//{
//	return PI * ((float)pow(R, 2) - (float)pow(r,2));
//}