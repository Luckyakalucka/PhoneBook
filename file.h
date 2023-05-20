#pragma once

// additionData(const char* filename, int countRecords, int id, Record* records):
int additionData(const char* filename, int countRecords, int id, int index, Record* records);

// readData(const char* filename, int* countRecords, int* id):
Record* readData(const char* filename, int* countRecords, int* id);

// writeData(const char* filename, int countRecords, int id, Record* records):
int writeData(const char* filename, int countRecords, int id, Record* records);