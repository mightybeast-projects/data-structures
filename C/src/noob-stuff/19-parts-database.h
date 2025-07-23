#include "stdio.h"
#include "stdlib.h"

#define PART_NAME_SIZE 100
#define DB_SIZE 5

typedef struct
{
    int id;
    char name[PART_NAME_SIZE];
    int quantity;
} Part;

void run();

void insert();
void search();
void update();
void print();

int readPartId();
Part* getPart(const int id);
void printPart(const Part* p);

Part db[DB_SIZE] = { 0 };
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
    if (dbIndex == DB_SIZE)
    {
        printf("Database is full\n");
        return;
    }

    const int id = readPartId();
    const Part* partPtr = getPart(id);

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

    Part part;
    part.id = id;
    strcpy(part.name, name);
    part.quantity = quantity;

    db[dbIndex++] = part;
}

void update()
{
    const int id = readPartId();
    Part* partPtr = getPart(id);

    if (partPtr)
    {
        int change;
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);

        partPtr->quantity += change;

        return printPart(partPtr);
    }

    printf("Could not find a part with id: %d\n", id);
}

void search()
{
    const int id = readPartId();
    const Part* partPtr = getPart(id);

    if (partPtr)
        return printPart(partPtr);

    printf("Could not find a part with id: %d\n", id);
}

void print()
{
    for (int i = 0; i < dbIndex; i++)
        if (db[i].id)
            printPart(&db[i]);
}

int readPartId()
{
    int id;

    printf("Enter part number: ");
    scanf("%d", &id);

    return id;
}

Part* getPart(const int id)
{
    for (int i = 0; i < dbIndex; i++)
        if (db[i].id == id)
            return &db[i];

    return NULL;
}

void printPart(const Part* p)
{
    printf("Id:%d\t Name:%s\t Quantity:%d\n", p->id, p->name, p->quantity);
}