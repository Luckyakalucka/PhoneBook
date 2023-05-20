#include "header.h"

int findIndexByStaticId(int countRecords, Record* records) {
    int index = 0;
    char strId[MAX_LEIGHT];
    unsigned id;
    customInput_s("Enter ID >> ", strId, MAX_LEIGHT, 1, '0', '9', 0, '0', '0', "");
    id = atoi(strId);
    while (index < countRecords) {
        if (records[index].id == id) {
            return index;
        }
        index++;
    }
    return -1;
}

int sortRecordsBySurname(int countRecords, Record* records) {
    for (int i = 0; i < countRecords - 1; i++) {
        for (int j = 0; j < countRecords - i - 1; j++) {
            if (strcmp(records[j].person.surname, records[j + 1].person.surname) > 0) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
    return 0;
}

int menu() {
    char input[MAX_LEIGHT];
    printf("\n\n----------------\n");
    printf(" 1 - Print Record\n");
    printf(" 2 - Add Record\n");
    printf(" 3 - Dlete Record\n");
    printf(" 4 - Edit Record\n");
    printf(" 5 - Find Record\n");
    printf(" 0 - Exit\n");
    printf(">>> ");
    customInput_s(">>> ", input, MAX_LEIGHT, 1, '0', '5', 0, '0', '0', "");
    return atoi(input);
}

int searchString(char* str, char* substr) {
    int j, len1 = (int)strlen(str), len2 = (int)strlen(substr);
    for (int i = 0; i <= len1 - len2; i++) {
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

int getGroupShort(char* str, Record* record) {
    int j = 0;
    if (record->group.relative) str[j++] = 'R';
    if (record->group.work) str[j++] = 'W';
    if (record->group.mates) str[j++] = 'M';
    if (record->group.favorite) str[j++] = 'F';
    str[j] = '\0';
    return 0;
}

int customInput_s(const char* title, char* value, int valueSize, int requiredFlag, char leftBorder, char rightBorder, int excpetFlag, char leftExceptBorder, char rightExceptBorder, char* additionalsChar) {
    int key;
    char* buffer = calloc(valueSize, sizeof(char));
    char* ptr = buffer;
    int buffer_count = 0;

    while (1) {
        printf("\r%s%s", title, buffer); // вивід на консоль
        key = _getch(); // прийом символу
        if (key == 224) {
            key = _getch();
            continue;
        }

        if (((key >= leftBorder && key <= rightBorder) && (!excpetFlag || !(key >= leftExceptBorder && key <= rightExceptBorder))) || strchr(additionalsChar, key)) { // перевірка на діапазон введення
                *ptr = key; // добавление к буферу справа

                if (buffer_count < valueSize) { // перевірка вмістимості
                    buffer_count++;
                    ptr++;
                }
                else *ptr = 0; // видалення символу якщо він не влазить до буферу  
            }


        if (key == VK_BACKSPACE && ptr > buffer) { // забой символу
            *--ptr = 0;
            printf("\b ");
        }

        if (key == VK_RETURN) {// ввод (enter)
            if (strlen(buffer)) {
                int i = 0;
                for ( ; i < buffer_count; i++) {
                    value[i] = buffer[i];
                }
                value[i] = 0;
                printf("\n");
                return 0;
            }
            else if (!requiredFlag) {
                value[0] = 0;
                printf("\n");
                return 0;
            }
        }
    }
}