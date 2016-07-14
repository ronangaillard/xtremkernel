//----------------------------------------------------------------------
//ERRORS constants
//----------------------------------------------------------------------


#define  ERR_NO_ERROR                     0
#define  ERR_OVERFLOW                 (-1) 
#define  ERR_WRONG_CONTEXT            (-2) //-- Wrong context context error
#define  ERR_WRONG_STATE              (-3) //-- Wrong state   state error
#define  ERR_TIMEOUT                  (-4) //-- Polling failure or timeout
#define  ERR_WRONG_PARAMETER              (-5)
#define  ERR_UNDERFLOW                (-6)
#define  ERR_OUT_OF_MEMORY            (-7)
#define  ERR_ILLEGAL_USE              (-8) //-- Illegal using
#define  ERR_NOT_EXISTING             (-9) //-- Non-valid or Non-existent object
#define  ERR_DELETED                  (-10) //-- Waiting object deleted

#define  NO_TIME_SLICE                   0
#define  MAX_TIME_SLICE             0xFFFE



//----------------------------------------------------------------------
//TASKS constants
//----------------------------------------------------------------------

#define NUMBER_OF_PRIORITY_LEVELS			32	//We'll use 32 as we are on a 32 bit processor, and that each bit represents a priority level, so that it's easier. And 32 priority levels are enough.

#define  STATE_NOT_RUNNING              0
#define  STATE_RUNNING              1


#define  TASK_START_ON_CREATION        1
#define  TASK_TIMER                 0x80
#define  TASK_IDLE                  0x40

#define  ID_TASK              ((int)0x47ABCF69)
#define  ID_SEMAPHORE         ((int)0x6FA173EB)
#define  ID_EVENT             ((int)0x5E224F25)
#define  ID_DATAQUEUE         ((int)0x8C8A6C89)
#define  ID_FSMEMORYPOOL      ((int)0x26B7CE8B)
#define  ID_MUTEX             ((int)0x17129E45)
#define  ID_RENDEZVOUS        ((int)0x74289EBD)


#define  EXIT_AND_DELETE_TASK          1

//TASK states

#define  TSK_STATE_RUNNABLE            0x01
#define  TSK_STATE_WAIT                0x04
#define  TSK_STATE_SUSPEND             0x08
#define  TSK_STATE_WAITSUSP            (TSK_STATE_SUSPEND | TSK_STATE_WAIT)
#define  TSK_STATE_DORMANT             0x10

//WAITING reasons

#define  TSK_WAIT_REASON_SLEEP            0x0001
#define  TSK_WAIT_REASON_SEM              0x0002
#define  TSK_WAIT_REASON_EVENT            0x0004
#define  TSK_WAIT_REASON_DQUE_WSEND       0x0008
#define  TSK_WAIT_REASON_DQUE_WRECEIVE    0x0010
#define  TSK_WAIT_REASON_MUTEX_C          0x0020          //-- ver 2.x
#define  TSK_WAIT_REASON_MUTEX_C_BLK      0x0040          //-- ver 2.x
#define  TSK_WAIT_REASON_MUTEX_I          0x0080          //-- ver 2.x
#define  TSK_WAIT_REASON_MUTEX_H          0x0100          //-- ver 2.x
#define  TSK_WAIT_REASON_RENDEZVOUS       0x0200          //-- ver 2.x
#define  TSK_WAIT_REASON_WFIXMEM          0x2000

#define  EVENT_ATTR_SINGLE            1
#define  EVENT_ATTR_MULTI             2
#define  EVENT_ATTR_CLR               4

#define  EVENT_WCOND_OR               8
#define  EVENT_WCOND_AND           0x10

#define  MUTEX_ATTR_CEILING           1
#define  MUTEX_ATTR_INHERIT           2



//----------------------------------------------------------------------
//Constants for Cortex M3
//----------------------------------------------------------------------



#define  TIMER_STACK_SIZE       64
#define  IDLE_STACK_SIZE        48
#define  MIN_STACK_SIZE         40      //--  +20 for exit func when ver GCC > 4

#define  NUMBER_OF_BITS_IN_INT            32

#define  ALIG                   sizeof(void*)

#define  MAKE_ALIG(a)  ((sizeof(a) + (ALIG-1)) & (~(ALIG-1)))

#define  PORT_STACK_EXPAND_AT_EXIT  20

  //----------------------------------------------------

#define  NUM_PRIORITY        NUMBER_OF_BITS_IN_INT  //-- 0..31  Priority 0 always is used by timers task

#define  WAIT_INFINITE       0xFFFFFFFF
#define  FILL_STACK_VALUE      0xFFFFFFFF
#define  INVALID_VALUE         0xFFFFFFFF


//HARD
   //--- I/O pins masks

#define  MASK_SSEL       (1<<12)
#define  MASK_SP1        (1<<3)
#define  MASK_SP2        (1<<4)
#define  MASK_LED1       (1<<9)
#define  MASK_SR_OE      (1<<7)
#define  MASK_RADIO_TX   (1<<25)
#define  MASK_CH_NUM     (1<<6)

#define  MASK_LED        (1<<26)
#define  LED_MASK        (1<<26)

//MEMORY_CHUNK
#define SIZE_INFINITE	0
#define MEMORY_STATUS_FREE	0
#define MEMORY_STATUS_ALLOCATED	1


#define COMMAND_BUFFER_SIZE 40
