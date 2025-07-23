#include "stdio.h"
#include "stdlib.h"

struct Part
{
    int id;
    char name[100];
    int quantity;
};

void run();
void execute(char command);
void insert();
void search();
void update();
void print();
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
           "(i - Insert, s - Search, u - Update, p - Print, q - Quit): \n");
    scanf(" %c", &command);

    execute(command);
}

void execute(char command)
{
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
}

void insert()
{
    if (dbIndex == sizeof(db) / sizeof(db[0]))
    {
        printf("Database is full\n");
        return;
    }

    int id;
    printf("Enter part number: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < dbIndex; i++)
    {
        if (db[i].id == id)
        {
            printf("Part with id %d is already in the database.\n", id);
            return;
        }
    }

    char name[100];
    printf("Enter part name: ");
    fgets(name, sizeof(name), stdin);
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
    int id;
    printf("Enter part number: ");
    scanf("%d", &id);

    for (int i = 0; i < dbIndex; i++)
    {
        if (db[i].id == id)
        {
            int change;
            printf("Enter change in quantity on hand: ");
            scanf("%d", &change);

            db[i].quantity += change;
            return;
        }
    }

    printf("Could not find a part with id: %d\n", id);
}

void search()
{
    int id;
    printf("Enter part number: ");
    scanf("%d", &id);

    for (int i = 0; i < dbIndex; i++)
    {
        if (db[i].id == id)
        {
            printPart(db[i]);
            return;
        }
    }

    printf("Could not find a part with id: %d\n", id);
}

void print()
{
    for (int i = 0; i < dbIndex; i++)
        if (db[i].id)
            printPart(db[i]);
}

void printPart(struct Part part)
{
    printf(
        "Id:%d\t Name:%s\t Quantity:%d\n", part.id, part.name, part.quantity);
}