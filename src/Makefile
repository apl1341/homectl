CC=g++
CPPFLAGS = -lboost_system -pthread

SRDEPS = com/session.h server/serversession.h
SROBJ = server/server.o com/session.o server/serversession.o

CLDEPS = com/session.h  client/clientsession.h
CLOBJ =  com/session.o  client/clientsession.o client/client.o

%.o: %.c $(SRDEPS) $(CLDEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

server/server: $(SROBJ)
	$(CC) -o $@ $^ $(CPPFLAGS)

client/client: $(CLOBJ)
	$(CC) -o $@ $^ $(CPPFLAGS)

clean:
	rm -rf */*.o
