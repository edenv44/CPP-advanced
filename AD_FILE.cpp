#include "AD_FILE.h"
#include <iostream>


////////////////////////////////  getters  //////////////////////////
string AD_File::getTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", lastUpadateTime);
	return buf;
}

string AD_File::getfileName() const 
{
	return this->FileName;
}

////////////////////////////////  setters  /////////////////////////
void AD_File::setTime()
{
	// current date/time based on current system
	time_t now = time(0);
	lastUpadateTime = localtime(&now);
}

string AD_File::setFileName(string fileName) throw (char*)
{
	//cout << "enter file name" << endl;
	//char* fileName = new char[20];
	//cin >> fileName;  // requst and accept name of new file to add to the array.
	int i = 0;
	while (strcmp(&fileName[i], "\0")) {
		if (!strcmp(&fileName[i], "<") || !strcmp(&fileName[i], ">") || !strcmp(&fileName[i], "/") || !strcmp(&fileName[i], "\\") || !strcmp(&fileName[i], "?") || !strcmp(&fileName[i], "*") || !strcmp(&fileName[i], ":") || !strcmp(&fileName[i], "|"))
		{
			throw ("invalid character provided");
		}
		i++;
	}
	return fileName;
}


//////////////////////////////// operators /////////////////////////////
bool AD_File :: operator == (AD_File* other)
{
	if (this->FileName == other->FileName) {
		return true;
	}
	return false;
}

AD_File AD_File :: operator = (AD_File* other)
{
	this->FileName = other->setFileName(other->FileName);
	this->setTime();
}


//////////////////////////////// builders //////////////////////////////
AD_File::AD_File(string FileName)
{
		this->FileName = setFileName(FileName);
		this->setTime();
}

AD_File::AD_File(AD_File* other)  // copy constructor
{
	this->FileName = other->FileName;
	this->lastUpadateTime = other->lastUpadateTime;
}