#include "header.h"

Record* getMemory(int countRecords, Record* records) {
    Record* tempRecords = (Record*)realloc(records, countRecords * sizeof(Record));
    if (tempRecords == NULL && countRecords >= 1) {
        free(tempRecords);
        free(records);
        printf("Memory problem!");
        exit(1);
    }
    return tempRecords;
}

int setRecordField(int num, int choice, Record* records) {
    switch ((enum fieldRecord)choice)
    {
    case SURNAME:
        printf("Surname: "); scanf_s("%s", &records[num].person.surname, MAX_LEIGHT);
        break;
    case NAME:
        printf("Name: "); scanf_s("%s", &records[num].person.name, MAX_LEIGHT);
        break;
    case PHONENUMBER:
        printf("Phone number: "); scanf_s("%s", &records[num].contact.phoneNumber, MAX_LEIGHT);
        break;
    case EMAIL:
        printf("Email: "); scanf_s("%s", &records[num].contact.email, MAX_LEIGHT);
        break;
    case WORK:
        printf("Company work: "); scanf_s("%s", &records[num].work.company, MAX_LEIGHT);
        printf("current position: "); scanf_s("%s", &records[num].work.position, MAX_LEIGHT);
        break;
    case GROUP:
        printf("Group (Relative Work Mates Favorite ex: WM): ");
        char buf[GROUP_COUNT]; scanf_s("%s", buf, GROUP_COUNT);
        records[num].group.flag = 0;
        for (int i = 0; i <= GROUP_COUNT; i++) {
            if (buf[i] == 'R' || buf[i] == 'r')
                records[num].group.relative = 1;
            else if (buf[i] == 'W' || buf[i] == 'w')
                records[num].group.work = 1;
            else if (buf[i] == 'M' || buf[i] == 'm')
                records[num].group.mates = 1;
            else if (buf[i] == 'F' || buf[i] == 'f')
                records[num].group.favorite = 1;
        }
    }
    return 0;
}

int findIdBySurname(char* surname, int countRecords, Record* records) {
    int id = 0;
    while (id < countRecords) {
        if (checkString(records[id].person.surname, surname) == 0) {
            return id;
        }
        id++;
    }
    return -1;
}

int sortRecordsBySurname(int countRecords, Record* records) {
    for (int i = 0; i < countRecords - 1; i++) {
        for (int j = 0; j < countRecords - i - 1; j++) {
            if (checkString(records[j].person.surname, records[j + 1].person.surname) > 0) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
    return 0;
}

int menu() {
    int input;
    printf("\n\n----------------\n");
    printf(" 1 - Print Record\n");
    printf(" 2 - Add Record\n");
    printf(" 3 - Dlete Record\n");
    printf(" 4 - Edit Record\n");
    printf(" 5 - Find Record\n");
    printf(" 0 - Exit\n");
    printf(">>> ");
    scanf_s("%d", &input);
    return input;
}

int searchString(char* str, char* substr) {
    int i, j, len1 = strlen(str), len2 = strlen(substr);

    for (i = 0; i <= len1 - len2; i++) {
        for (j = 0; j < len2; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == len2) {
            return i;
        }
    }

    return -1;
}

int strlen(char* str) {
    int len = 0;

    while (*str != '\0') {
        len++;
        str++;
    }

    return len;
}

int checkString(char* s1, char* s2) {
    while ((*s1 && *s2) && (*s1 == *s2)) {
        s1++; s2++;
    }
    return *s1 - *s2;
}

int getGroupShort(int id, char* str, Record* records) {
    int j = 0;
    if (records[id].group.favorite) str[j++] = 'F';
    if (records[id].group.relative) str[j++] = 'R';
    if (records[id].group.work) str[j++] = 'W';
    if (records[id].group.mates) str[j++] = 'M';
    str[j++] = '\0';
    return 0;
}