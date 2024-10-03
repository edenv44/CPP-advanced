#include "DataFile.h"
#define SIZE 0

bool isEmpty(int size);

void main() {
	DataFile** R2D2 = new DataFile*[SIZE];  // prepare allocated array.
	int choice;  // request command from user.
	cout << "1. Print Files" << endl;
	cout << "2. Add Files" << endl;
	cout << "3. Edit Files" << endl;
	cout << "4. Exit" << endl;
	cin >> choice;  // accept command from user.
	int counter = 0;  // counts how many objects in array.
	bool has;
	while (choice < 1 || choice > 3) {  // incase first command is invalid.
		cout << "enter valid number. valid first options are 1-3" << endl;  // request next command.
		cout << "1. Print Files" << endl;
		cout << "2. Add Files" << endl;
		cout << "3. Edit Files" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;  // accept next command.
	}
	while (choice != 4) {  // if option 4 (exit) is selected then will exit loop and free array.
		if (choice == 1 || choice == 3 || choice == 4) {
			has = isEmpty(counter);
		}
		if (choice == 1 && has == false) {
			for (int g = 0; g < counter; g++) {
				cout << "\nfile number " << g + 1 << " is:" << endl;
				R2D2[g]->dir(R2D2[g]);
			}
		}
		if (choice == 2) {
			counter++;  // an object will be added.
			DataFile** temp = new DataFile*[counter];///(DataFile*)malloc(sizeof(DataFile) * counter);
			for (int i = 0; i < counter - 1; i++) {  // transfer all files to temp.
				temp[i] = R2D2[i];
			}
			///R2D2[i].~DataFile();  // free allocated memory from R2D2 because already located in temp
			delete[] R2D2;
			R2D2 = new DataFile*[counter];///(DataFile*)malloc(sizeof(DataFile) * counter);  // allocate additional memory for R2D2.
			for (int i = 0; i < counter - 1; i++) {  // transfer all files back to R2D2.
				R2D2[i] = temp[i];
			}
			delete[](temp);  // get rid of temp.
			DataFile* object = new DataFile;
			R2D2[counter - 1] = object;  // new empty slot in R2D2 will recieve new object.
		}
		if (choice == 3 && has == false) {  // in case option 3 was chosen.
			char* filename1 = new char;
			cout << "please enter a file name you would like to edit: ";
			cin >> filename1;  // request filename from user in order to search.
			int ok = 0;
			for (int i = 0; i < counter; i++) {  // run through all sections in the array.
				if (!strcmp(R2D2[i]->getFileName(), filename1)) {  // compare name given to files in array.
					char* data = new char;
					cout << "file found, what data would you like instead?" << endl;
					cin >> data;
					R2D2[i]->setData(data);
					ok++;  // meant to check if file was found or not.
					break;
				}
			}
			if (ok == 0) {
				cout << "file not found" << endl;  // line will activate only if break function isn't used.
			}
		}
		while (choice < 1 || choice > 3) {
			cout << "enter next command" << endl;
			cout << "1. Print Files" << endl;  // after the decision has been fullfiled ask for next command.
			cout << "2. Add Files" << endl;
			cout << "3. Edit Files" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;  // accept new command.
		}
	}
	delete[](R2D2);  // exit command has been selected so free al memory allocated and end process.
}

bool isEmpty(int size) {
	if (size == 0) {
		cout << "array is currently empty, please enter a different command" << endl;
		return true;
	}
	return false;
}