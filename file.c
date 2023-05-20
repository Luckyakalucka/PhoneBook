#include "header.h"

int additionData(const char* filename, int countRecords, int id, int index, Record* records) {
    FILE* f;
    errno_t err = fopen_s(&f, filename, "r+b");
    if (err != 0 || index < 0) {
        return 1;
    }
    fseek(f, 0, SEEK_SET);
    fwrite(&countRecords, sizeof(int), 1, f);
    fwrite(&id, sizeof(int), 1, f);
    fseek(f, sizeof(Record) * index, SEEK_CUR);
    fwrite(&records[index], sizeof(Record), 1, f);
    fclose(f);
    return 0;
}

Record* readData(const char* filename, int* countRecords, int* id) {
    FILE* f;
    errno_t err = fopen_s(&f, filename, "rb");
    if (err != 0) {
        err = fopen_s(&f, filename, "w");
        if (f != 0)
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
    FILE* f;
    errno_t err = fopen_s(&f, filename, "wb");
    if (err != 0) {
        return 1;
    }
    fwrite(&countRecords, sizeof(int), 1, f);
    fwrite(&id, sizeof(int), 1, f);
    fwrite(records, sizeof(Record), countRecords, f);
    fclose(f);
    return 0;
}