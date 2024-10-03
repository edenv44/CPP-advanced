#include "DataFile.h"

// Static variable initialization
int DataFile::NumberOfFiles = 0;

/******************** Methods [gets] ********************/

// [1/3]: File Name
char* DataFile::getFileName() const
{
	return FileName;
}

// [2/3]: Data
char* DataFile::getData() const
{
	return Data;
}

// [3/3]: Last Update Time
char* DataFile::getLastUpdateTime() const
{
	char buf[80]; strftime(buf, sizeof(buf), "%d/%m/%Y %X", LastUpdateTime);
	char* stringTime = new char[strlen(buf) + 1];
	strcpy(stringTime, buf); return stringTime;
}

/******************** Methods [sets] ********************/

// [1/3]: File Name
void DataFile::setFileName(const char* fileName)
{
	// Variables
	char container[Tsize];			// input string holder
	strcpy(container, fileName);

	// Validation loop
	while ((strchr(container, '<')) || (strchr(container, '>')) || (strchr(container, '/')) || (strchr(container, '\\')) || (strchr(container, '|')) || (strchr(container, ':')) || (strchr(container, '?')) || (strchr(container, '*')))
	{
		cout << "Invalid characters in string." << endl << "A file name cannot contain any of the following characters: ( < > / \\ | : ? *). " << endl << "Retry entering a filename: ";
		cin >> container;
	}

	// file name insertion
	FileName = new char[strlen(container) + 1];
	strcpy(FileName, container);
}

// [2/3]: Data
void DataFile::setData(const char* data)
{
	Data = new char[strlen(data) + 1];
	strcpy(Data, data);
}

// [3/3]: Last Update Time
void DataFile::setLastUpdateTime()
{
	// current date/time based on current system
	time_t now = time(0);
	LastUpdateTime = localtime(&now);
}

/******************** Methods [specials] ********************/

// [1/2]: Get Size
double DataFile::getSize() const
{
	return (strlen(Data) + 1);
}

// [2/2]: Dir
void DataFile::dir()
{
	double KBsize = (getSize() / 1024);
	cout << "File Details: " << getLastUpdateTime() << " " << KBsize << " KB" << " " << getFileName() << endl;
}

/******************** Methods [personal] ********************/

// [1/3]: Free file name
void DataFile::freeFileName()
{
	delete[] FileName;
}

// [2/3]: Free data
void DataFile::freeData()
{
	delete[] Data;
}

// [3/3]: Set time (with arguments)
void DataFile::setLastUpdateTime(const tm _tm)
{
	// set the time from time object
	time_t t1 = time(0);
	struct tm* now = localtime(&t1);
	(*now).tm_mday = _tm.tm_mday;
	(*now).tm_mon = _tm.tm_mon;
	(*now).tm_year = _tm.tm_year;
	(*now).tm_hour = _tm.tm_hour;
	(*now).tm_min = _tm.tm_min;
	(*now).tm_sec = _tm.tm_sec;
	LastUpdateTime = now;
}

/******************** Constructors ********************/

// [1/4]: Empty Constructor
DataFile::DataFile()
{
	// File counter updating
	NumberOfFiles++;

	// Variables
	char Tstring1[Tsize];		// to be used as the name of the file and the chained file name with the index
	char Tstring2[Tsize];		// to be used as the file counter in string format
	
	// Preperations
	strcpy(Tstring1, "EmptyFile");			// name insertion to temporary string 1
	_itoa(NumberOfFiles, Tstring2, 10);		// index insertion to temporary string 2
	strcat(Tstring1, Tstring2);				// name + index insertion to temporary string 1
	
	// Data updateing
	setFileName(Tstring1);
	setData("");
	setLastUpdateTime();
}

// [2/4]: Argument Constructor
DataFile::DataFile(const char* fileName, const char* data)
{
	setFileName(fileName);
	setData(data);
	setLastUpdateTime();
}

// [3/4]: Copying Constructor
DataFile::DataFile(const DataFile& other)
{
	this->FileName = NULL;
	this->Data = NULL;
	*this = other;
}

// [4/4]: Destructor
DataFile::~DataFile()
{
	NumberOfFiles--;
	delete[] FileName;
	delete[] Data;
}

/******************** Operators ********************/

// [1/5]: Operator =
const DataFile& DataFile::operator = (const DataFile& other)
{
	if (this != &other)
	{
		delete[] FileName;
		setFileName(other.FileName);
		delete[] Data;
		setData(other.Data);
		LastUpdateTime = other.LastUpdateTime;
	}
	return *this;
}

// [2/5]: Operator ==
bool DataFile::operator == (const DataFile& other) const
{
	// Condition [1/2]: Adress comparison	// MAKE A FUNCTION
	if (this == &other)
	{
		cout << "The comparison is irrelevent because the files are the same." << endl;
		return false;
	}

	// Condition [2/2]: Data comparison
	
	if ((strcmp(this->getFileName(), other.getFileName()) == 0) && (strcmp(this->getData(), other.getData()) == 0))
	{
		//cout << "The files have the same names and data." << endl;
		return true;
	}
	else
	{
		//cout << "The files do not have the same names and data." << endl;
		return false;
	}
}

// [3/5]: Operator < (smaller than)
bool DataFile::operator < (const DataFile& other) const
{
	// Condition [1/2]: Adress comparison	// MAKE A FUNCTION
	if (this == &other)
	{
		cout << "The comparison is irrelevent because the files are the same." << endl;
		return false;
	}

	// Condition [2/2]: Weight comparison (smaller than)
	if ((this->getSize()) < (other.getSize()))
	{
		cout << "The current file is smaller than the other one." << endl;
		return true;
	}
	else
	{
		cout << "The current file is not smaller than the other one." << endl;
		return false;
	}
}

// [4/5]: Operator > (bigger than)
bool DataFile::operator > (const DataFile& other) const
{
	// Condition [1/2]: Adress comparison	// MAKE A FUNCTION
	if (this == &other)
	{
		cout << "The comparison is irrelevent because the files are the same." << endl;
		return false;
	}

	// Condition [2/2]: Weight comparison (bigger than)
	if ((this->getSize()) > (other.getSize()))
	{
		cout << "The current file is bigger than the other one." << endl;
		return true;
	}
	else
	{
		cout << "The current file is not bigger than the other one." << endl;
		return false;
	}
}

// [5/5]: Operator << (output)
ostream& operator << (ostream& out, const DataFile& object)
{
	out << object.getLastUpdateTime() << " " << object.getSize() / 1024 << " KB" << " " << object.getFileName() << endl;
	return out;
}
