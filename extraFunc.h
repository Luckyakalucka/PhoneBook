#pragma once

#define VK_RETURN    13
#define VK_BACKSPACE  8
#define VK_ESC		 27

// findIndexByStaticId(int countRecords, Record* records):
int findIndexByStaticId(int countRecords, Record* records);

// sortRecordsBySurname(int countRecords, Record* records):
int sortRecordsBySurname(int countRecords, Record* records);

// menu():
int menu();

// searchString(char* str, char* substr):
int searchString(char* str, char* substr);

// getGroupShort(char* str, Record* record):
int getGroupShort(char* str, Record* record);


int customInput_s(const char* title, char* value, int valueSize, int requiredFlag, char leftBorder, char rightBorder, int excpetFlag, char leftExceptBorder, char rightExceptBorder, char* additionalsChar);