
/* submodule includes */

#include "common.h"

/* macro definitions */

#define ARM_STACK_POPS            16                                            /* unstacks 16 registers (r0 - r15) */

#define SET_PSP_MASK              0x3                                           /* this mask switches msp to psp */
#define PSR_DEFAULT_MASK          0x21000000                                    /* see ARM cortex-M data sheet for register details*/
#define MAX_TASK_NUMBER           10                                            /* max number of tasks allowed on this kernel */
#define MAX_SP_ADDRESS            0x20001000                                    /* end of the RAM */
#define MAX_SP_SIZE_WORDS         256                                           /* total task stack is 256 words in size (256*4 = 1024 bytes) */
#define INIT_SP_TASK_ADDRESS      (MAX_SP_ADDRESS - MAX_SP_SIZE_BYTES)          /* address of the first stack pointer */

/* global vars */

/* enumeration definitions */

enum task_state
{
  TASK_FREE,
  TASK_READY,
  TASK_RUNNING,
};

/* struct definitions */

struct task_t
{
  uint32_t* asp;                                                                /* virtual asending (climbs up) task stack */
  enum task_state state;
};

/* function declarations */

void taskInit();
bool taskSpawn(void (*fcnp)(void));
void taskKill();
bool taskReady(struct task_t* taskReady);