#ifndef __errors_h
#define __errors_h

#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MSG_LEN 64

#define err_abort(code,text) do {\
	fprintf (stderr, "%s at \"%s\":%d: %s\n", \
		text,__FILE__,__LINE__,strerror(code)); \
	abort (); \
	}while (0)

#define errno_abort(text) do { \
	fprintf (stderr,"%s at \"%s\":%d: %s\n", \
		text,__FILE__,__LINE__,strerror(errno)); \
	abort (); \
	} while (0)

#endif
