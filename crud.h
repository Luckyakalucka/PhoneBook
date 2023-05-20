#pragma once

// getMemory(int countRecords, Record* records):
Record* getMemory(int, Record*);

// addRecord(int* countRecords, int* sId, Record* records):
Record* addRecord(int*, int*, Record*);

// editRecord(int countRecords, Record* records):
int editRecord(int, Record*);

// deleteRecord(int* countRecords, Record* records):
Record* deleteRecord(int*, Record*);


int findRecords(int countRecords, Record* records);


void printMenuRecordsHead();

void printMenuRecordsBody(Record* record);

// printMenuRecords(int countRecords, Record* records):
int printMenuRecords(int, Record*);

// printRecord(int countRecords, Record* records):
int printRecord(int, Record*);

// setRecordField(, int choice, Record* record):
int setRecordField(int, Record*);
