#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char ch;
    int count;
    struct node *next;
} Node;

int search(char ch, Node *head) {
    Node *current = head;
    while (current != NULL) {
        if (current->ch == ch) {
            (current -> count) += 1;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main(int argc, char *argv[1]) {
    FILE *fp = fopen("main.c", "r");
    if (fp == NULL) {
        printf("File not found\n");
        printf("You can use ./main <file path> to try again\n");
        fclose(fp);
        return 0;
    }

    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("File not found\n");
            fclose(fp);
            return 0;
        }
    }

    //hash 
    Node *hash[127] = {NULL};
    char tmp;
    Node *head = NULL;
    Node *current = head;

    while ((tmp = getc(fp)) != EOF) {
        if (hash[tmp] != NULL) {
            (hash[tmp]->count) += 1;
        } else {
            Node *new = (Node *)malloc(sizeof(Node));
            new->ch = tmp;
            new->count = 1;
            new->next = NULL;
            hash[tmp] = new;
            if (head == NULL) {
                head = new;
                current = head;
            } else {
                current->next = new;
                current = new;
            }
        }
    }
    //----------------------------------------------

    fclose(fp);

    //print node
    while (head != NULL) {
        printf("%c: %d\n", head->ch, head->count);
        head = head->next;
    }
    return 0;
}