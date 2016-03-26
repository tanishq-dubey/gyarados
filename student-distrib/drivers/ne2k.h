#include "../libs/lib.h"
#include "../libs/types.h"

#define BASE_NE2K_PORT          0xc100

#define NE2K_RESET_PORT         BASE_NE2K_PORT + 0x1F
#define NE2K_STATUS_PORT        BASE_NE2K_PORT + 0x07
#define NE2K_ISR_PORT           BASE_NE2K_PORT + 0x07
#define NE2K_CR_PORT            BASE_NE2K_PORT + 0x00

/* Busy code = 1000 0000 */
#define NE2K_BUSY_CODE          0x80

/* Mask & unmask (1111 1111 and 0000 0000) */
#define NE2K_MASK_ALL           0xFF
#define NE2K_MASK_NONE          0x00

/* Equivalent to 0010 0001 */
#define NE2K_INIT_CR            0x21

void ne2k_init(void);
