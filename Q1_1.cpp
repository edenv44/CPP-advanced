//#define _CRT_SECURE_NO_WARNINGS
//#define Asize 3		// constant 1st dimention array size
//#define Tsize 20	// temporary string holder array size
//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//
//// Global expression structure (Paragraph A)
//typedef struct Expression
//{
//	char sign;					// to be used as the calculation mark ('+', '-', '*', '/', '%')
//	char* arrNums[Asize];		// to be used as the calculation array
//}Expression;
//
//// Function declaration block
//void createExpression(Expression& exp);
//void calculation(Expression& exp);
//void printExpression(const Expression& exp);
//
//
///******************** START OF PROGRAME ********************/
//
//void main()
//{
//	Expression exp1;	// Expression object to be used to check all functions
//
//	// Paragraph B
//	createExpression(exp1);
//
//	// Paragraph C
//	calculation(exp1);
//
//	// Paragraph D
//	printExpression(exp1);
//
//	// Deletion block
//	delete[] exp1.arrNums[0];
//	delete[] exp1.arrNums[1];
//	delete[] exp1.arrNums[2];
//}
//
//// Input function for arrNums[0],[1], sign (paragraph B)
//void createExpression(Expression &exp)
//{
//	// assisting variables
//	int numA;				// 1st number in integer format
//	int numB;				// 2nd number in integer format
//	char num1[Tsize];		// 1st number in string format
//	char num2[Tsize];		// 2nd number in string format
//	char temp;				// calculation sign
//
//	// input (instructions)
//	cout << "Enter two numbers, and after that the calculation sign" << endl;
//
//	// input (1st number)
//	cout << "1st number: ";								// instructions
//	cin >> numA;										// input to integer
//	if (numA < 0) { numA *= (-1); }						// positivity forcing
//	_itoa(numA, num1, 10);								// int to string conversion & input to string
//	exp.arrNums[0] = new char[strlen(num1) + 1];		// memory allocation
//	strcpy(exp.arrNums[0], num1);						// input to array
//	
//	// input (2nd number)
//	cout << "2nd number: ";								// instructions
//	cin >> numB;										// input to integer
//	if (numB < 0) { numB *= (-1); };					// positivity forcing
//	_itoa(numB, num2, 10);								// int to string conversion & input to string
//	exp.arrNums[1] = new char[strlen(num2) + 1];		// memory allocation
//	strcpy(exp.arrNums[1], num2);						// input to array
//
//	// input (sign)
//	cout << "Calculation sign: ";																	// instructions
//	cin >> temp;																					// input to temporary sign
//	while ((temp != '+') && (temp != '-') && (temp != '*') && (temp != '/') && (temp != '%'))		// correct sign checking
//	{
//		cout << "Invalid sign. Reminder: possible signs (+, -, *, /, %)" << endl;					// instructions with help
//		cout << "Calculation sign: ";																// instructions
//		cin >> temp;																				// input to temporary sign
//	}
//	exp.sign = temp;																				// input to sign
//}
//
//// Calculation function to calculate the two numbers (paragraph C)
//void calculation(Expression& exp)
//{
//	// assisting variables
//	int num1 = atoi(exp.arrNums[0]);	// 1st number conversion from string to int
//	int num2 = atoi(exp.arrNums[1]);	// 2nd number conversion from string to int
//	int num3;							// caclulation result in int format
//	char num4[Tsize];					// calculation result in string format
//
//	// calculation block
//	switch (exp.sign)
//	{
//		case '+': num3 = num1 + num2; break;
//		case '-': num3 = num1 - num2; if (num3 < 0) { num3 *= (-1); } break;
//		case '*': num3 = num1 * num2; break;
//		case '/': if (num2 == 0) { cout << "Math error. Cannot divide by zero" << endl; } exit(1); num3 = num1 / num2; break;
//		case '%': if (num2 == 0) { cout << "Math error. Cannot divide by zero" << endl; } exit(1); num3 = num1 % num2; break;
//		default: cout << "An unknown error has occured: calculation -> switch block" << endl; break;
//	}
//
//	// insersion block
//	_itoa(num3, num4, 10);							// int to string conversion
//	exp.arrNums[2] = new char[strlen(num4) + 1];	// memory allocation
//	strcpy(exp.arrNums[2], num4);					// insertion to the result coloumn
//}
//
//// Printing function for the entire proccess (paragraph D)
//void printExpression(const Expression& exp)
//{
//	cout << "Calculation and result: " << exp.arrNums[0] << " " << exp.sign << " " << exp.arrNums[1] << " = " << exp.arrNums[2] << endl;
//}