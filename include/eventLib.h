/* Standard headers for PAPI test applications.
    This file is customized to hide Windows / Unix differences.
*/

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/wait.h>
#if (!defined(NO_DLFCN) && !defined(_BGL) && !defined(_BGP))
#include <dlfcn.h>
#endif

#include <errno.h>
#include <memory.h>
#if !defined(__FreeBSD__) && !defined(__APPLE__)
#include <malloc.h>
#endif
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <pthread.h>
#include "papiStdEventDefs.h"


#include "artico3.h"


#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN  "\033[1;32m"
#define NORMAL "\033[0m"

static int TESTS_COLOR = 0;

typedef struct papi_action_s {
	char *action_id;
	long long *counterValues; //size = eventCodeSetSize
	char *component_id;
	int num_counters;
	unsigned long long time_zero;
	unsigned long long time_init_action;
	unsigned long long time_end_action;
	FILE* papi_output_file;
	int* papi_eventCodeSet;
	unsigned long papi_eventSet;
	FILE* eventset_test_file;
	
} papi_action_s;