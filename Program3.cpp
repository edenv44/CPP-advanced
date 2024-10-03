#include "Folder.h"

void main()
{
	/***** Mission A *****/ 
	Folder F1("ListDataFiles.txt", "Path1");	// DOES THE PATH HAVE A SPECIFIC MEANING?
	
	/***** Mission B *****/
	F1.getBossList(F1.getFolderName(), F1.getFolderName()).readAllFiles("ListDataFiles.txt");

	/***** Mission C *****/
	cout << "---------- Files from the given text document ----------" << endl;
	cout << F1;
	cout << "--------------------------------------------------------" << endl << endl;

	/***** Mission D *****/
	DataFile DF3("fileName3.txt", "hello world3");
	DataFile DF0;
	F1.getBossList() += DF3;
	F1.getBossList() += DF0;

	/***** Mission E *****/
	cout << "---------- Files from the updated files list ----------" << endl;
	cout << F1;
	cout << "-------------------------------------------------------" << endl;

	/***** Mission F *****/
	int BFindex = F1.getBossList().bigFile();
	switch (BFindex)
	{
	case -1: cout << "There are no data files in the array, so the method is irrelevant." << endl; break;
	default: cout << "The biggest file from the array is:" << endl << F1.getBossList().getMasterArray()[BFindex] << endl; break;
	}
	

	/***** Mission G *****/
	char buffer1[Tsize];
	char buffer2[Tsize];

	cout << "You are currently in mission g." << endl;
	cout << "Enter are folder name for the new folder: ";
	cin >> buffer1;
	cout << "Enter a path for the new folder: ";
	cin >> buffer2;
	Folder F2(buffer1,buffer2);		// DOES THE PATH HAVE A SPECIFIC MEANING?

	/***** Mission H *****/
	DataFile DF1, DF2;
	F2.getBossList() += DF1;
	F2.getBossList() += DF2;

	/***** Mission I *****/
	cout << "Comparing F1 to F2..." << endl;
	if (F1 == F2)
	{
		cout << "The files are equal." << endl;
	}
	else
	{
		cout << "The files are not equal." << endl;
	}
	
	cout << "Equalizing between F1 and F2..." << endl;
	cout << "Comparing between F1 and F2 again..." << endl;
	if (F1 == F2)
	{
		cout << "The files are equal." << endl;
	}
	else
	{
		cout << "The files are not equal." << endl;
	}
}