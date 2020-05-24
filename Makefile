CC = gcc

PROG= udpserver

SRCS=	udpsever.c 
OBJS=	udpserver.o


LDLIBS +=

all:	$(PROG) 

$(PROG):	$(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJS) 
	$(RM) $(PROG)



