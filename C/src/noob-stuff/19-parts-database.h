#include "stdio.h"
#include "stdlib.h"

#define PART_NAME_SIZE 100

struct Part
{
    int id;
    char name[PART_NAME_SIZE];
    int quantity;
};

void run();

void insert();
void search();
void update();
void print();

int readPartId();
struct Part* getPart(int id);
void printPart(struct Part part);

struct Part db[5] = { 0 };
int dbIndex = 0;

void partsDatabase()
{
    while (1)
        run();
}

void run()
{
    char command;
    printf("Enter command code "
           "(i - Insert, s - Search, u - Update, p - Print, q - Quit): ");
    scanf(" %c", &command);

    switch (command)
    {
    case 'i':
        insert();
        break;
    case 's':
        search();
        break;
    case 'u':
        update();
        break;
    case 'p':
        print();
        break;
    case 'q':
        exit(0);
        break;
    default:
        return;
    }

    printf("---------------------\n");
}

void insert()
{
    if (dbIndex == sizeof(db) / sizeof(db[0]))
    {
        printf("Database is full\n");
        return;
    }

    int id = readPartId();
    struct Part* partPtr = getPart(id);

    if (partPtr)
    {
        printf("Part with id %d is already in the database.\n", id);
        return;
    }

    getchar();

    char name[PART_NAME_SIZE];
    printf("Enter part name: ");
    fgets(name, PART_NAME_SIZE, stdin);
    name[strlen(name) - 1] = '\0';

    int quantity;
    printf("Enter quantity on hand: ");
    scanf("%d", &quantity);

    struct Part part;
    part.id = id;
    part.quantity = quantity;
    strcpy(part.name, name);

    db[dbIndex++] = part;
}

void update()
{
    int id = readPartId();
    struct Part* partPtr = getPart(id);

    if (partPtr)
    {
        int change;
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);

        partPtr->quantity += change;

        return printPart(*partPtr);
    }

    printf("Could not find a part with id: %d\n", id);
}

void search()
{
    int id = readPartId();
    struct Part* partPtr = getPart(id);

    if (partPtr)
        return printPart(*partPtr);

    printf("Could not find a part with id: %d\n", id);
}

void print()
{
    for (int i = 0; i < dbIndex; i++)
        if (db[i].id)
            printPart(db[i]);
}

int readPartId()
{
    int id;

    printf("Enter part number: ");
    scanf("%d", &id);

    return id;
}

struct Part* getPart(int id)
{
    for (int i = 0; i < dbIndex; i++)
        if (db[i].id == id)
            return &db[i];

    return NULL;
}

void printPart(struct Part p)
{
    printf("Id:%d\t Name:%s\t Quantity:%d\n", p.id, p.name, p.quantity);
}