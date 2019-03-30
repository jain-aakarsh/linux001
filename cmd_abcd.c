#include <common.h>
#include <command.h>




static int do_abcd(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[]) 
{

printf("HELLO WORLD");
printf("arg1 %s",argv[1]);

}


U_BOOT_CMD(
	abcd,	2,	1,do_abcd,
	"get/set/reset date & time",
	"[MMDDhhmm[[CC]YY][.ss]]\ndate reset\n"
	"  - without arguments: print date & time\n"
	"  - with numeric argument: set the system date & time\n"
	"  - with 'reset' argument: reset the RTC"
);
