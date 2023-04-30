#include "header.h"

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
    int num = (*countRecords) - 1;
    for (int choice = 1; choice <= 6; choice++) {
        setRecordField(num, choice, records);
    }
    records[num].id = ++(*id);
    return records;
}

int editRecord(int countRecords, Record* records) {
    int input;
    char surnameTmp[MAX_LEIGHT];
    printf("Enter surname for search >> ");
    scanf_s("%s", surnameTmp, MAX_LEIGHT);
    int num = findIdBySurname(surnameTmp, countRecords, records);
    if (num == -1) {
        return 1;
    }
    printf("\n1. Surname");
    printf("\n2. Name");
    printf("\n3. Phone number");
    printf("\n4. E-mail address");
    printf("\n5. Groups");
    printf("\n\nChoose what you want to change >> ");
    scanf_s("%d", &input);
    setRecordField(num, input, records);
    return num;
}

Record* deleteRecord(int* countRecords, Record* records) {
    char surnameTmp[MAX_LEIGHT];
    printf("Enter surname for search >> ");
    scanf_s("%s", surnameTmp, MAX_LEIGHT);
    int num = findIdBySurname(surnameTmp, *countRecords, records);
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

int printMenuRecords(int countRecords, Record* records) {
    printf("%20s |%20s |%20s |%20s |%6s\n", "Surname", "Name", "Phone number", "Email", "Group");
    if (countRecords > 0) {
        for (int i = 0; i < countRecords; i++) {
            for (int k = 0; k <= 94; k++) printf("-");
            char group[GROUP_COUNT+2]; getGroupShort(i, group, records);
            printf("\n%20s |%20s |%20s |%20s |%6s\n", records[i].person.surname, records[i].person.name, records[i].contact.phoneNumber, records[i].contact.email, group);
        }
    }
    else {
        printf("\n  Oops, there is nothing here, to create an entry, select the appropriate menu item!");
    }
    return 0;
}

int printRecord(int countRecords, Record* records) {
    char surnameTmp[MAX_LEIGHT];
    printf("Enter surname for search >> ");
    scanf_s("%s", surnameTmp, MAX_LEIGHT);
    int num = findIdBySurname(surnameTmp, countRecords, records);
    if (num == -1) {
        return 1;
    }
    printf("\nSurname: %s", records[num].person.surname);
    printf("\nName: %s", records[num].person.name);
    printf("\nEmail address: %s", records[num].contact.email);
    printf("\nPhone number: %s", records[num].contact.phoneNumber);
    printf("\nGroups: ");
    if (records[num].group.favorite) printf("Favorite ");
    if (records[num].group.relative)  printf("Relative ");
    if (records[num].group.work) printf("Work ");
    if (records[num].group.mates) printf("Mates ");
    printf("\nWork: %s, %s", records[num].work.company, records[num].work.position);
    printf("\n");
    system("pause");
    return 0;
}