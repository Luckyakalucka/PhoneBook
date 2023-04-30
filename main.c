#include "header.h"

int main(int argc, char** argv) {
	char filename[50] = "file.bin";
	int menuChoice, sID = 0, countRecords = 0;
	Record* records = readData(filename, &countRecords, &sID);
	do {
		printMenuRecords(countRecords, records);
		menuChoice = menu();
		switch ((enum menu)menuChoice)
		{
		case PRINT_ONE:
			printRecord(countRecords, records);
			break;
		case ADD:
			records = addRecord(&countRecords, &sID, records);
			additionData(filename, countRecords, sID, records);
			break;
		case EDIT:
			editRecord(countRecords, records);
			writeData(filename, countRecords, sID, records);
			break;
		case DEL:
			records = deleteRecord(&countRecords, records);
			writeData(filename, countRecords, sID, records);
			break;
		}
		system("cls");
	} while (menuChoice != EXIT);
	return 0;
}