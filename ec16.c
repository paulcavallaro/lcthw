#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char *name;
        int age;
        int height;
        int weight;
} Person;

Person *Person_create(char *name, int age, int height, int weight)
{
        Person *who = malloc(sizeof(Person));
        assert(who != NULL);

        who->name = strdup(name);
        who->age = age;
        who->height = height;
        who->weight = weight;

        return who;
}

void Person_destroy(Person *who)
{
        assert(who != NULL);

        free(who->name);
        free(who);
}


void Person_print(Person *who)
{
        printf("Person { ");
        printf("Name: %s, ", who->name);
        printf("Age: %d, ", who->age);
        printf("Height: %d, ", who->height);
        printf("Weight: %d }\n", who->weight);
}

void Person_print_val(Person who)
{
        printf("Person { ");
        printf("Name: %s, ", who.name);
        printf("Age: %d, ", who.age);
        printf("Height: %d, ", who.height);
        printf("Weight: %d }\n", who.weight);
}

int main(int argc, char *argv[])
{
        // make two people structures
        Person joe = {"Joe Alex", 32, 64, 140};
        Person frank = {"Frank Blank MORE HERE YEA", 20, 72, 180};

        Person tom;
        tom.name = "Tom Thomas";
        tom.age = 45;
        tom.height = 70;
        tom.weight = 195;

        // print them out and where they are in memory
        printf("Joe is at memory location %p:\n", &joe);
        Person_print(&joe);
        Person_print_val(joe);

        printf("Frank is at memory location %p:\n", &frank);
        Person_print(&frank);
        Person_print_val(frank);

        printf("Tom is at memory location %p:\n", &joe);
        Person_print(&tom);
        Person_print_val(tom);

        // make everyone age 20 years and print them again
        joe.age += 20;
        joe.height -= 2;
        joe.weight += 40;
        Person_print(&joe);

        frank.age += 20;
        frank.weight += 20;
        Person_print(&frank);

        return 0;
}
