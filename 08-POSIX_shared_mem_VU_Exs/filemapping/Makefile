.PHONY: all clean

CC := gcc
LINK_OPTION := lrt 

all:
	${CC} producer.c -o producer -${LINK_OPTION}
	${CC} consumer.c -o consumer -${LINK_OPTION}

clean:
	rm -rf producer consumer