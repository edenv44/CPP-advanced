#include "ArrayListFiles.h"
#include <fstream>

// ******************** Constructors ******************** //

// [1/4]: Empty constructor - implemented in the h file

// [2/4]: Argument constructor - unnecessary

// [3/4]: Copying constructor
ArrayListFiles::ArrayListFiles(const ArrayListFiles& other)
{
	for (int i = 0; i < MAsize; i++)
	{
		this->MasterArray[i] = NULL;
	}
	this->MasterArray = NULL;
	*this = other;
}

// [4/4]: Destructor
ArrayListFiles::~ArrayListFiles()
{
	for (int i = 0; i < MAsize; i++)
	{
		delete[] MasterArray[i];
	}
	delete[] MasterArray;
}

// ******************** Operators ******************** //

// [1/2]: Operator =
const ArrayListFiles& ArrayListFiles::operator = (const ArrayListFiles& other)
{
	if (this != &other)
	{
		// Array deletion
		for (int i = 0; i < MAsize; i++)
		{
			delete[] MasterArray[i];
		}
		delete[] MasterArray;

		// array insertion
		MasterArray = new DataFile * [MAsize];
		for (int i = 0; i < MAsize; i++)
		{
			MasterArray[i] = new DataFile();
			*(MasterArray[i]) = *(other.MasterArray[i]);
		}
	}
	return *this;
}

// [2/2]: Operator +=
ArrayListFiles& ArrayListFiles::operator += (const DataFile& other)
{
	// searching loop
	bool found = false;		// found file indicator
	for (int i = 0; i < MAsize; i++)
	{
		if (*(MasterArray[i]) == other)		// == *other?, correct direfferencing in the master array?
		{
			cout << "The current file was not added because it already exists in the file array." << endl;
			found = true;
			break;
		}
	}

	// insertion block
	if (found == false)
	{
		// temporary array creation and insertion
		DataFile** TempArray = new DataFile * [MAsize];
		for (int i = 0; i < MAsize; i++)
		{
			TempArray[i] = new DataFile();
			*(TempArray[i]) = *(MasterArray[i]);
		}

		// master array deletion
		for (int i = 0; i < MAsize; i++)
		{
			delete MasterArray[i];
		}
		delete[] MasterArray;

		// master array recreation with updated size
		MasterArray = new DataFile * [MAsize + 1];
		for (int i = 0; i < MAsize; i++)
		{
			MasterArray[i] = new DataFile();
			*(MasterArray[i]) = *(TempArray[i]);
		}

		// temporary array deletion
		for (int i = 0; i < MAsize; i++)
		{
			delete TempArray[i];
		}
		delete[] TempArray;

		// new object insertion
		*MasterArray[MAsize] = other;
		MAsize++;

		// output
		cout << "File Added successfully." << endl;
	}
	return *this;
}

// ******************** Methods [general] ******************** //

// [1/2]: big file
int ArrayListFiles::bigFile() const
{
	int index;			// the index of the heaviest file
	int i = 1;			// loop index initialization

	// case (1/2): empty array
	if (MAsize == 0)
	{
		return -1;
	}

	// case (2/2): one file array
	if (MAsize == 1)
	{
		return 0;
	}

	/* general case */
	// initial search
	if (MasterArray[i] > MasterArray[i - 1])
	{
		index = i;
	}
	else
	{
		index = (i - 1);
	}

	// biggest file locating
	for (i = 2; i < MAsize; i++)
	{
		if (MasterArray[i] > MasterArray[index])
		{
			index = i;
		}
	}
	return index;
}

// [2/2]: read all files
void ArrayListFiles::readAllFiles(const char* const FileName)
{
	// variables
	char buffer[150];		// line container
	int Lines = 0;			// number of lines in the file

	// file opening
	ifstream in(FileName, ios::in);
	if (!in.is_open())
	{
		cout << "Unable to open the file." << endl;
		return;
	}

	// line counting block
	in.seekg(0, ios::beg);
	while (!in.eof())
	{
		in.getline(buffer, 150);
		Lines++;
	}

	// Master Array reallocation [1/2]		// DO I NEED TO TAKE INTO CONSIDERATION THAT THERE WHERE ITEMS IN THE MASTER ARRAY BEFORE READING FROM THE FILE?
	for (int i = 0; i < MAsize; i++)
	{
		delete MasterArray[i];
	}
	delete[] MasterArray;

	// Master Array reallocation [2/2]
	MasterArray = new DataFile * [Lines];
	for (int i = 0; i < Lines; i++)
	{
		MasterArray[i] = new DataFile();
	}
	
	// reading and insertion
	in.seekg(0, ios::beg);
	for (int i = 0; i < Lines; i++)
	{
		// variables
		in.getline(buffer, 150);
		tm TempTime;

		// reading block (entire line string)
		char* date = strtok(buffer, " ");		// temporary date container
		char* time = strtok(NULL, " ");			// temporary time container
		char* TempName = strtok(NULL, " ");		// temporary name container
		char* TempData = strtok(NULL, "\n");	// temporary data container

		// reading block (date string)
		TempTime.tm_mday = atoi(strtok(date, "/"));
		TempTime.tm_mon = atoi(strtok(NULL, "/"));
		TempTime.tm_year = atoi(strtok(NULL, "/"));

		// reading block (time string)
		TempTime.tm_hour = atoi(strtok(time, ":"));
		TempTime.tm_min = atoi(strtok(NULL, ":"));
		TempTime.tm_sec = atoi(strtok(NULL, ":"));

		//insertion block
		MasterArray[i]->setFileName(TempName);
		MasterArray[i]->setData(TempData);
		MasterArray[i]->setLastUpdateTime(TempTime);	// COULD BE PROBLEMATIC BECAUSE IT IS TAKEN FROM THE INTERNET
	}

	// file closing
	in.close();

	// MasterArray size updating
	MAsize = Lines;
}

// ********************  Methods [gets] ******************** //

// [1/2]: get master array
DataFile** ArrayListFiles::getMasterArray() const
{
	return MasterArray;
}

// [2/2]: get master array size
int ArrayListFiles::getMAsize() const
{
	return MAsize;
}