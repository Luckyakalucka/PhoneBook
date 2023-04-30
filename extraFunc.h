#pragma once

Record* getMemory(int countRecords, Record* records);
int setRecordField(int num, int choice, Record* records);
int findIdBySurname(char* surname, int countRecords, Record* records);
int sortRecordsBySurname(int countRecords, Record* records);
int menu();
int searchString(char* str, char* substr);
int strlen(char* str);
int checkString(char* s1, char* s2);

int getGroupShort(int id, char* str, Record* records);