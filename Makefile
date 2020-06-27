build:
	gcc list.c -o list
	gcc slist.c -o slist
	gcc stailq.c -o stailq
	gcc tailq.c -o tailq

clean:
	\rm -f list slist stailq tailq