#include <stdio.h>
#include <stdbool.h>

#include "selection_sort.h"
#include "array_utilities.h"

char double_cmp(void *a, void *b) {
    double a_value = *((double *) a);
    double b_value = *((double *) b);

    if (a_value < b_value) return -1;
    else if (a_value == b_value) return 0;
    else return 1;
}

typedef struct Person {
    char *name;
    unsigned int age;
    float height;
} Person;

char person_cmp(void *a, void *b) {
    Person *ap = (Person *) a;
    Person *bp = (Person *) b;

    if (ap->age < bp->age) return -1;
    else if (ap->age == bp->age) return 0;
    else return 1;
}

int main(void) {
    int n;

    /*double arr[] = {0.2, -1, 3.14, 4, 2.7, 0.17, 3};

    n = sizeof(arr) / sizeof(double);

    selection_sort(double, arr, n, true, double_cmp);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    putchar('\n');*/

    n = 4;
    Person people[n];

    people[0].name = "Carlos";
    people[0].age = 18;
    people[0].height = 1.70;

    people[1].name = "Natasha";
    people[1].age = 40;
    people[1].height = 1.72;

    people[2].name = "Eduardo";
    people[2].age = 20;
    people[2].height = 1.65;

    people[3].name = "Steve";
    people[3].age = 16;
    people[3].height = 1.68;

    selection_sort(Person, people, n, false, person_cmp);

    for (int i = 0; i < n; i++)
        printf(
            "Person: name = %s, age = %u, height = %.2f\n",
            people[i].name,
            people[i].age,
            people[i].height);

    return 0;
}