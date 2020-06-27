#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

int main(void)
{
    LIST_HEAD(listhead, entry)
    head = LIST_HEAD_INITIALIZER(head);
    struct listhead *headp; /* List head. */
    struct entry
    {
        LIST_ENTRY(entry)
        entries; /* List. */
        int value;
    } * n1, *n2, *n3, *np, *np_temp;

    LIST_INIT(&head); /* Initialize the list. */

    n1 = malloc(sizeof(struct entry)); /* Insert at the head. */
    n1->value = 4;
    LIST_INSERT_HEAD(&head, n1, entries);

    n2 = malloc(sizeof(struct entry)); /* Insert at the head. */
    n2->value = 9;
    LIST_INSERT_HEAD(&head, n2, entries);

    LIST_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }

    n3 = LIST_FIRST(&head);
    printf("\nHead: %d\n\n", n3->value);
    LIST_REMOVE(n3, entries);
    free(n3);
    puts("After remove:");
    LIST_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }
    free(n1);
    return 0;
}