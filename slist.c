#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

int main(void)
{
    SLIST_HEAD(slisthead, entry)
    head = SLIST_HEAD_INITIALIZER(head);
    struct slisthead *headp; /* Singly-linked List head. */
    struct entry
    {
        SLIST_ENTRY(entry)
        entries; /* Singly-linked List. */
        int value;
    } * n1, *n2, *n3, *np;

    SLIST_INIT(&head);                 /* Initialize the list. */
    n1 = malloc(sizeof(struct entry)); /* Insert at the head. */
    n1->value = 4;
    SLIST_INSERT_HEAD(&head, n1, entries);
    n2 = malloc(sizeof(struct entry)); /* Insert at the head. */
    n2->value = 9;
    SLIST_INSERT_HEAD(&head, n2, entries);
    SLIST_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }
    n3 = SLIST_FIRST(&head);
    SLIST_REMOVE_HEAD(&head, entries); /* Deletion from the head. */
    printf("\nHead: %d\n\n", n3->value);
    free(n3);
    puts("After remove:");
    SLIST_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }

    free(n1);
    return 0;
}
