#pragma once

int additionData(const char* filename, int countRecords, int id, Record* records);
Record* readData(const char* filename, int* countRecords, int* id);
int writeData(const char* filename, int countRecords, int id, Record* records);