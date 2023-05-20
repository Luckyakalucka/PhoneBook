#include "header.h"

Record* getMemory(int countRecords, Record* records) {
    Record* tempRecords = (Record*)realloc(records, countRecords * sizeof(Record));
    if (tempRecords == NULL && countRecords >= 1) {
        free(tempRecords);
        printf("Memory problem!");
        system("pause");
        return records;
    }
    return tempRecords;
}

Record* addRecord(int* countRecords, int* id, Record* records) {
    if (*countRecords < MAX_RECORD) {
        *countRecords += 1;
        records = getMemory(*countRecords, records);
    }
    else {
        printf("  The maximum number of records has already been created, in order to add a new one you need to delete the old one!\n");
        system("pause");
        return records;
    }
    for (int choice = 1; choice <= 6; choice++) {
        setRecordField(choice, &records[(*countRecords) - 1]);
    }
    records[(*countRecords) - 1].id = ++(*id);
    sortRecordsBySurname(*countRecords, records);
    return records;
}

int editRecord(int countRecords, Record* records) {
    char input[MAX_LEIGHT];
    int num = findIndexByStaticId(countRecords, records);
    if (num == -1) {
        return -1;
    }
    printf("\n1. Surname");
    printf("\n2. Name");
    printf("\n3. Phone number");
    printf("\n4. E-mail address");
    printf("\n5. Groups");
    printf("\n6. Work\n\n");
    customInput_s("Choose what you want to change >> ", input, MAX_LEIGHT, 1, '1', '6', 0, '0', '0', "");
    setRecordField(atoi(input), &records[num]);
    sortRecordsBySurname(countRecords, records);
    return num;
}

Record* deleteRecord(int* countRecords, Record* records) {
    int num = findIndexByStaticId(*countRecords, records);
    if (num == -1) {
        return records;
    }
    while (num < *countRecords) {
        records[num] = records[num + 1];
        num++;
    }
    *countRecords -= 1;
    records = getMemory(*countRecords, records);
    return records;
}


int findRecords(int countRecords, Record* records) {
    char input[MAX_LEIGHT];
    char inputStr[MAX_LEIGHT];
    printf("\n1. Surname");
    printf("\n2. Name");
    printf("\n3. Groups");
    printf("\n4. Company work");
    customInput_s("\n\nBy which parameter you want to find a record >> ", input, MAX_LEIGHT, 1, '1', '4', 0, '0', '0', "");
    

    int flag = 0;
    switch (atoi(input))
    {
    case 1:
        customInput_s("Surname: ", inputStr, MAX_LEIGHT, 1, 'A', 'z', 1, '[', '`', "");
        printMenuRecordsHead();
        for (int i = 0; i < countRecords; i++) {
            if (strcmp(records[i].person.surname, inputStr) == 0) {
                printMenuRecordsBody(&records[i]);
                flag = 1;
            }
        }
        break;
    case 2:
        customInput_s("Name: ", inputStr, MAX_LEIGHT, 1, 'A', 'z', 1, '[', '`', "");
        printMenuRecordsHead();
        for (int i = 0; i < countRecords; i++) {
            if (strcmp(records[i].person.name, inputStr) == 0) {
                printMenuRecordsBody(&records[i]);
                flag = 1;
            }
        }
        break;
    case 3:
        customInput_s("Group [Relative / Work / Mates / Favority] (ex: WM): ", \
            inputStr, MAX_LEIGHT, 0, 0, 0, 0, '0', '0', "RWMFrwmf");
        printMenuRecordsHead();
        for (int i = 0; i < countRecords; i++) {
            if (strchr(inputStr, 'R') || strchr(inputStr, 'r')) {
                if (records[i].group.relative == 1) {
                    printMenuRecordsBody(&records[i]);
                    flag = 1;
                }
            }
            else if (strchr(inputStr, 'W') || strchr(inputStr, 'w')) {
                if (records[i].group.work == 1) {
                    printMenuRecordsBody(&records[i]);
                    flag = 1;
                }
            }
            else if (strchr(inputStr, 'M') || strchr(inputStr, 'm')) {
                if (records[i].group.mates == 1) {
                    printMenuRecordsBody(&records[i]);
                    flag = 1;
                }
            }
            else if (strchr(inputStr, 'F') || strchr(inputStr, 'f')) {
                if (records[i].group.favorite == 1) {
                    printMenuRecordsBody(&records[i]);
                    flag = 1;
                }
            }
        }
        break;
    case 4:
        customInput_s("Company work: ", inputStr, MAX_LEIGHT, 1, 'A', 'z', 1, '[', '`', "");
        printMenuRecordsHead();
        for (int i = 0; i < countRecords; i++) {
            if (strcmp(records[i].work.company, inputStr) == 0) {
                printMenuRecordsBody(&records[i]);
                flag = 1;
            }
        }
        break;
    }

    if (flag == 0) {
        printf("\n  Nothing was found for your search!\n");
        system("pause");
    }

    return flag;
}

void printMenuRecordsHead() {
    printf("%4s |%30s |%30s |%30s |%30s |%6s\n", "ID", "Surname", "Name", "Phone number", "Email", "Group");
}

void printMenuRecordsBody(Record* record) {
    for (int k = 0; k <= 139; k++) printf("-");
    char group[GROUP_COUNT]; getGroupShort(group, record); //
    printf("\n%4d |%30s |%30s |%30s |%30s |%6s\n", record->id, record->person.surname, record->person.name, record->contact.phoneNumber, record->contact.email, group);
}

int printMenuRecords(int countRecords, Record* records) {
    printMenuRecordsHead();
    if (countRecords > 0) {
        for (int i = 0; i < countRecords; i++) {
            printMenuRecordsBody(&records[i]);
        }
    }
    else {
        printf("\n  Oops, there is nothing here, to create an entry, select the appropriate menu item!");
    }
    return 0;
}

int printRecord(int countRecords, Record* records) {
    int num = findIndexByStaticId(countRecords, records);
    if (num == -1) {
        return 1;
    }
    printf("\nSurname: %s", records[num].person.surname);
    printf("\nName: %s", records[num].person.name);
    printf("\nEmail address: %s", records[num].contact.email);
    printf("\nPhone number: %s", records[num].contact.phoneNumber);
    printf("\nGroups: ");
    if (records[num].group.favorite)  printf("Favorite ");
    if (records[num].group.relative)  printf("Relative ");
    if (records[num].group.work) printf("Work ");
    if (records[num].group.mates) printf("Mates ");
    printf("\nWork: %s, %s\n", records[num].work.company, records[num].work.position);
    system("pause");
    return 0;
}

int setRecordField(int choice, Record* records) {
    char buf[GROUP_COUNT];
    switch ((enum fieldRecord)choice)
    {
    case SURNAME:
        customInput_s("Surname: ", records->person.surname, MAX_LEIGHT, 1, 'A', 'z', 1, '[', '`', "");
        break;
    case NAME:
        customInput_s("Name: ", records->person.name, MAX_LEIGHT, 1, 'A', 'z', 1, '[', '`', "");
        break;
    case PHONENUMBER:
        customInput_s("Phone number: ", records->contact.phoneNumber, MAX_LEIGHT, 1, '0', '9', 0, '0', '0', "+() ");
        break;
    case EMAIL:
        customInput_s("Email: ", records->contact.email, MAX_LEIGHT, 0, 32, 126, 0, '0', '0', "");
        break;
    case WORK:
        customInput_s("Company work: ", records->work.company, MAX_LEIGHT, 0, 32, 126, 0, '0', '0', "");
        customInput_s("Current position: ", records->work.position, MAX_LEIGHT, 0, 32, 126, 0, '0', '0', "");
        break;
    case GROUP:
        customInput_s("Group [Relative / Work / Mates / Favority] (ex: WM): ",\
            buf, GROUP_COUNT, 0, 0, 0, 0, '0', '0', "RWMFrwmf");
        records->group.flag = 0;
        for (int i = 0; i <= GROUP_COUNT; i++) {
            if (buf[i] == 'R' || buf[i] == 'r')
                records->group.relative = 1;
            else if (buf[i] == 'W' || buf[i] == 'w')
                records->group.work = 1;
            else if (buf[i] == 'M' || buf[i] == 'm')
                records->group.mates = 1;
            else if (buf[i] == 'F' || buf[i] == 'f')
                records->group.favorite = 1;
        }
    }
    return 0;
}
