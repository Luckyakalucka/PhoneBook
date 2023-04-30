#pragma once

#define MAX_LEIGHT 50
#define MAX_RECORD 20
#define GROUP_COUNT 4

struct Person {
	char surname[MAX_LEIGHT];
	char name[MAX_LEIGHT];
};

struct Contact {
	char phoneNumber[MAX_LEIGHT];
	char email[MAX_LEIGHT];
};

union Group {
	struct {
		unsigned char relative : 1;
		unsigned char work : 1;
		unsigned char mates : 1;
		unsigned char favorite : 1;
	};
	unsigned char flag;
};

struct Work {
	char company[MAX_LEIGHT];
	char position[MAX_LEIGHT];
};

typedef struct {
	int id;
	struct Person person;
	struct Contact contact;
	struct Work work;
	union Group group;
} Record;
