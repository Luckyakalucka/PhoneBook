#include "header.h"

int additionData(const char* filename, int countRecords, int id, Record* records) {
    FILE* f = fopen(filename, "r+b");
    if (f == NULL) {
        return 1;
    }
    fseek(f, 0, SEEK_SET);
    fwrite(&countRecords, sizeof(int), 1, f);
    fwrite(&id, sizeof(int), 1, f);
    fseek(f, sizeof(Record) * (countRecords - 1), SEEK_CUR);
    fwrite(records + countRecords - 1, sizeof(Record), 1, f);
    fclose(f);
    return 0;
}

Record* readData(const char* filename, int* countRecords, int* id) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        f = fopen(filename, "w");
        fclose(f);
        return NULL;
    }
    fread(countRecords, sizeof(int), 1, f);
    fread(id, sizeof(int), 1, f);
    Record* records = (Record*)malloc(sizeof(Record) * *countRecords);
    if (records != NULL) {
        fread(records, sizeof(Record), *countRecords, f);
    }
    fclose(f);
    return records;
}

int writeData(const char* filename, int countRecords, int id, Record* records) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        return 1;
    }
    fwrite(&countRecords, sizeof(int), 1, f);
    fwrite(&id, sizeof(int), 1, f);
    fwrite(records, sizeof(Record), countRecords, f);
    fclose(f);
    return 0;
}