#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

int main(void)
{
    STAILQ_HEAD(stailhead, entry)
    head = STAILQ_HEAD_INITIALIZER(head);
    struct stailhead *headp; /* Singly-linked tail queue head. */
    struct entry
    {
        STAILQ_ENTRY(entry)
        entries; /* Tail queue. */
        int value;
    } * n1, *n2, *n3, *np;

    STAILQ_INIT(&head); /* Initialize the queue. */

    n1 = malloc(sizeof(struct entry)); /* Insert at the tail. */
    n1->value = 4;
    STAILQ_INSERT_TAIL(&head, n1, entries);

    n2 = malloc(sizeof(struct entry)); /* Insert at the tail. */
    n2->value = 9;
    STAILQ_INSERT_TAIL(&head, n2, entries);

    STAILQ_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }

    n3 = STAILQ_FIRST(&head);
    printf("\nHead: %d\n\n", n3->value);
    STAILQ_REMOVE_HEAD(&head, entries);
    free(n3);
    puts("After remove:");
    STAILQ_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }

    free(n2);
    return 0;
}