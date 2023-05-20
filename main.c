#include "header.h"

int main(int argc, char** argv) {
	char filename[50] = "file.bin";
	int menuChoice, sID = 0, countRecords = 0, findFlag = 0;
	Record* records = readData(filename, &countRecords, &sID);
	do {
		if (findFlag == 0) {
			system("cls");
			printMenuRecords(countRecords, records);
		}
		findFlag = 0;
		menuChoice = menu();
		switch ((enum menu)menuChoice)
		{
		case PRINT_ONE:
			printRecord(countRecords, records);
			break;
		case ADD:
			records = addRecord(&countRecords, &sID, records);
			additionData(filename, countRecords, sID, countRecords-1, records);
			break;
		case EDIT:
			additionData(filename, countRecords, sID, editRecord(countRecords, records), records);
			break;
		case DEL:
			records = deleteRecord(&countRecords, records);
			writeData(filename, countRecords, sID, records);
			break;
		case FIND:
			findFlag = findRecords(countRecords, records);
			break;
		}
	} while (menuChoice != EXIT);
	return 0;
}