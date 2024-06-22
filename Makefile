CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c89
TARGET=monty

all:
	@i=0; \
	total=20; \
	while [ $$i -le $$total ]; do \
		perc=$$((200*$$i/$$total % 2 + 100*$$i/$$total)); \
		printf "\rCompiling: %3d%%" $$perc; \
		sleep 0.05; \
		i=$$((i+1)); \
	done; \
	printf "\r%$${COLUMNS}s\r"; \
	if $(CC) $(CFLAGS) *.c -o $(TARGET); then \
		printf "\nCOMPILED"; \
		sleep 2; \
		printf "\r%$${COLUMNS}s\r"; \
	fi

clean:
	rm -f $(TARGET)
