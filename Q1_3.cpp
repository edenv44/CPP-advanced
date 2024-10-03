#define _CRT_SECURE_NO_WARNINGS
#define Tsize 50
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// Function declerations
char** stringBreaker(char sentence[], int length);
char* stringDuplicator(char* word);

void main()
{
	/** PART A */

	// Variables
	char sentence[Tsize];		// temporary sentence holder
	char* Sptr = sentence;		// running pointer to the sentence
	int counter = 0;			// number of spaces in the sentence
	int length;					// number of words in the sentence
	char** arr;					// main 2D array

	// Input
	cout << "Enter a sentence: ";			// instructions
	cin.getline(sentence, Tsize, '\n');		// input to temporary sentence holder

	// Length finding
	while (*Sptr != '\0')		// limit mark for the pointer
	{
		if (*Sptr == ' ')		// space detection
		{
			counter++;			// number of spaces growth
		}
		Sptr++;					// pointer advancment
	}
	length = counter + 1;		// number of words insertion

	// String breaking function
	arr = stringBreaker(sentence, length);

	// Printing block A
	cout << endl << "The 2nd dimension of the array: ";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	/** PART B */

	for (int i = 0; i < length; i++)
	{
		arr[i] = stringDuplicator(arr[i]);
	}

	// Printing block B
	cout << endl << "The duplicated 2nd dimension of the array: ";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// Deletion block
	for (int i = 0; i < length; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

// Function for the 2D array manipulation (PART A)
char** stringBreaker(char sentence[], int length)
{
	// Variables
	char word[Tsize];	// temporary word container
	char* Sptr;			// running string pointer and space finder 
	char** arr;			// to return as the 2D array

	// 1st dimension memory allocation
	arr = new char* [length];

	// Function actions
	for (int i = 0; i < length; i++)
	{
		// string breaking
		if (i == 0)
		{
			Sptr = strtok(sentence, " ");
		}
		else
		{
			Sptr = strtok(NULL, " ");
		}

		// 2nd dimention memory allocation
		arr[i] = new char[strlen(Sptr) + 1];

		// 2nd dimention insertion
		arr[i] = Sptr;
	}
	return arr;
}

// function for word duplications (PART B)
char* stringDuplicator(char* word)
{
	// temporary pointer to hold the word
	char* Tptr = new char[strlen(word) + 1];		// memory allocation 
	strcpy(Tptr, word);								// value copying

	// length extension & memory reallocation
	int length = strlen(word);						// length of the current word
	word = new char[(length * 2) + 1];				// new memory allocation

	// string chaining
	strcpy(word, Tptr);								// re - insertion of the word
	strcat(word, Tptr);								// word duplication
	return word;
}