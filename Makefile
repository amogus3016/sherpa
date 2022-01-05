CC=gcc
CFLAGS=-O2 -Wall vte3

$(info Installing Sherpa...)

all: sherpa
sherpa: sherpa.o
sherpa.o: sherpa.c

$(info Cleaning up...)

clean:
	rm -f sherpa sherpa.o
run: sherpa
	./sherpa

$(info Sherpa was installed sucessfully.)
