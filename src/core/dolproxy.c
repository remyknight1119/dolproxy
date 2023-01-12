#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/epoll.h>

#include "dlp_lib.h"

static const char *
dlp_program_version = "1.0.0";//PACKAGE_STRING;

static const struct option 
dlp_long_opts[] = {
	{"help", 0, 0, 'H'},
	{"debug", 0, 0, 'd'},
	{"config", 0, 0, 'c'},
	{"signal", 0, 0, 's'},
	{0, 0, 0, 0}
};

static const char *
dlp_options[] = {
	"--config       -c	configure file\n",	
	"--debug        -d	debug mode\n",	
	"--signal       -s	send signal to master process\n",	
	"--help         -H	Print help information\n",	
};

static void 
dlp_help(void)
{
	int     index;

	fprintf(stdout, "Version: %s\n", dlp_program_version);

	fprintf(stdout, "\nOptions:\n");
	for(index = 0; index < DLP_ARRAY_SIZE(dlp_options); index++) {
		fprintf(stdout, "  %s", dlp_options[index]);
	}
}

static const char *
dlp_optstring = "Hdc:s:";

int
main(int argc, char **argv)  
{
    char                    *cf = NULL;
    char                    *cmd = NULL;
    //dlp_srv_conf_t           conf = {};
    int                     c = 0;
    //int                     ret = 0;

    while((c = getopt_long(argc, argv, 
                    dlp_optstring,  dlp_long_opts, NULL)) != -1) {
        switch(c) {
            case 'H':
                dlp_help();
                return 0;

            case 'c':
                cf = optarg;
                break;

            case 'd':
                //dlp_log_print = 1;
                break;

            case 's':
                cmd = optarg;
                break;

            default:
                dlp_help();
                return -1;
        }
    }

    if (cf == NULL) {
        fprintf(stderr, "Please input configure file by -c!\n");
        return -1;
    }

#if 0
    ret = dlp_srv_conf_parse(&conf, cf);
    if (ret != DV_OK) {
        fprintf(stderr, "Parse %s failed!\n", cf);
        return -DV_ERROR;
    }

#endif
    if (cmd != NULL) {
    //    return -dlp_server_send_signal(conf.sc_pid_file, cmd);
    }

#if 0
    dlp_argc = argc;
    dlp_argv = argv;

    return -dlp_server_cycle(&conf);
#endif
    return 0;
}
