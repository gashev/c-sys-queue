#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

int main(void)
{
    TAILQ_HEAD(tailhead, entry)
    head = TAILQ_HEAD_INITIALIZER(head);
    struct tailhead *headp; /* Tail queue head. */
    struct entry
    {
        TAILQ_ENTRY(entry)
        entries; /* Tail queue. */
        int value;
    } * n1, *n2, *n3, *np;

    TAILQ_INIT(&head); /* Initialize the queue. */

    n1 = malloc(sizeof(struct entry)); /* Insert at the tail. */
    n1->value = 4;
    TAILQ_INSERT_TAIL(&head, n1, entries);

    n2 = malloc(sizeof(struct entry)); /* Insert at the tail. */
    n2->value = 9;
    TAILQ_INSERT_TAIL(&head, n2, entries);

    TAILQ_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }

    n3 = TAILQ_FIRST(&head);
    printf("\nHead: %d\n\n", n3->value);
    TAILQ_REMOVE(&head, n3, entries);
    free(n3);
    puts("After remove:");
    TAILQ_FOREACH(np, &head, entries)
    {
        printf("%d\n", np->value);
    }

    free(n2);
    return 0;
}