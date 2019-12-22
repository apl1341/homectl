CC=g++
CPPFLAGS = -lboost_system -pthread
DEPS = session.h
OBJ = server.o session.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS)
