#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    char value[32];
    struct node *next;
};

struct node *list = NULL;

struct node *add(struct node *list, int key, char *value) {
    struct node *newList = malloc(sizeof(struct node));
    newList->key = key;
    strcpy(newList->value, value);
    newList->next = list;

    return newList;
}

struct node *get(struct node *list, int key) {
    while(list->key != key && list->next) {
        list = list->next;
    }
    return list;
}

int main() {
    list = add(list, 3000, "Bern");
    list = add(list, 4000, "Basel");
    list = add(list, 8000, "Zürich");
    struct node *n = get(list, 4000);
    printf("%d: %s\n", n->key, n->value);
}