#pragma once

Record* addRecord(int* countRecords, int* sId, Record* records);
int editRecord(int countRecords, Record* records);
Record* deleteRecord(int* countRecords, Record* records);
int printMenuRecords(int countRecords, Record* records);
int printRecord(int countRecords, Record* records);