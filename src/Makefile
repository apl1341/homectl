CC=g++
CPPFLAGS = -lboost_system -pthread

SRDEPS = com/session.h server/serversession.h
SROBJ = server/server.o com/session.o server/serversession.o

CLDEPS = com/session.h  client/clientsession.h
CLOBJ =  com/session.o  client/clientsession.o client/client.o

all: server client

%.o: %.c $(SRDEPS) $(CLDEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

server: $(SROBJ)
	$(CC) -o server/server $^ $(CPPFLAGS)

client: $(CLOBJ)
	$(CC) -o client/client $^ $(CPPFLAGS)

clean:
	rm -rf */*.o
