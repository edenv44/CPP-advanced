#include "Folder.h"

// ******************** Methods [gets] ******************** //

// [1/3]: Get folder name
char* Folder::getFolderName() const
{
	return FolderName;
}

// [2/3]: Get folder path
char* Folder::getFolderPath() const
{
	return Path;
}

// [3/3]: get boss list
ArrayListFiles Folder::getBossList(char* FolderName, char* Path) const
{
	
	return BossList;
}

// ******************** Methods [sets] ******************** //

// [1/2]: Set folder name
void Folder::setFolderName(const char* folderName)
{
	FolderName = new char[strlen(folderName) + 1];
	strcpy(FolderName, folderName);
}

// [2/2]: Set path
void Folder::setPath(const char* path)
{
	Path = new char[strlen(path) + 1];
	strcpy(Path, path);
}

// ******************** Constructors ******************** //

// [1/4]: Empty constructor
Folder::Folder()
{
	setFolderName("NewFolder");
	setPath("");
}

// [2/4]: Argument constructor
Folder::Folder(const char* folderName, const char* path)
{
	setFolderName(folderName);
	setPath(path);
}

// [3/4]: Copying constructor
Folder::Folder(const Folder& other)
{
	this->FolderName = NULL;
	this->Path = NULL;
	*this = other;
}

// [4/4]: Destructor
Folder::~Folder()
{
	delete[] FolderName;
	delete[] Path;
}

// ******************** Operators ******************** //

// [1/3]: Operator =
const Folder& Folder::operator = (const Folder& other)
{
	if (this != &other)
	{
		delete[] FolderName;
		setFolderName(other.FolderName);
		delete[] Path;
		setPath(other.Path);
		BossList = other.BossList;
	}
	return *this;
}

// [2/3]: operator <<
ostream& operator << (ostream& out, const Folder& object)
{
	// Folder details
	out << object.Path << "\\" << object.FolderName << " ";

	// DataFiles details
	for (int i = 0; i < object.BossList.getMAsize(); i++)
	{
		out << object.getBossList(object.getFolderName(), object.getFolderPath()).getMasterArray()[i] << endl;
	}
	return out;
}

// [3/3]: operator ==
bool Folder::operator == (const Folder& other) const
{
	// variables
	bool IsSameFolder = false;					// indication of the folders are the same or not
	int FilesNumber = BossList.getMAsize();		// the total number of files in the array
	int IdenticalFiles = 0;						// the number of identical data files found in the loop

	// searching loop
	for (int i = 0; i < FilesNumber; i++)
	{
		if (BossList.MasterArray[i] == other.BossList.MasterArray[i])
		{
			IdenticalFiles++;
		}
	}

	// conclusion
	if (IdenticalFiles == FilesNumber)
	{
		IsSameFolder = true;
	}
	return IsSameFolder;
}