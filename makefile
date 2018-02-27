CC          = gcc
#CFLAGS      = -fno-stack-protector -fno-dwarf2-cfi-asm -fno-asynchronous-unwind-tables 
CFLAGS      = 
all: 
	$(CC) -S $(CFLAGS) server.c
	$(CC) -o server $(CFLAGS) server.c
	$(CC) -o client $(CFLAGS) client.c util.c
	$(CC) -o escape_client $(CFLAGS) escape_client.c util.c
	$(CC) -o got_writer $(CFLAGS) got_writer.c util.c gen_pload.c
	$(CC) -o overflow $(CFLAGS) -DNO_STACK_CANARIES overflow.c util.c
	$(CC) -o aslr_overflow $(CFLAGS) -DNO_STACK_CANARIES aslr_overflow.c util.c
	$(CC) -o aslr_canary_overflow $(CFLAGS) aslr_overflow.c util.c
	$(CC) -o brute_force $(CFLAGS) brute_force.c util.c
clean:
	rm -f *.o client server escape_client got_writer overflow aslr_overflow aslr_canary_overflow brute_force *.s

