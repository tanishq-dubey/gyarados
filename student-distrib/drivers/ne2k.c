#include "ne2k.h"

uint8_t card_data[32];

void ne2k_init(void) {
    int i = 0;

    // reset the card
    outb(inb(NE2K_RESET_PORT), NE2K_RESET_PORT);

    // wait until the card is finished resetting
    while((inb(NE2K_STATUS_PORT) & NE2K_BUSY_CODE) == 0);

    // mask all interrupts
    outb(NE2K_MASK_ALL, NE2K_ISR_PORT);

    outb(NE2K_INIT_CR, NE2K_CR_PORT);      // page 0, no DMA, stop
    outb(0x49, BASE_NE2K_PORT + 0x0E);     // set word-wide access
    outb(0, BASE_NE2K_PORT + 0x0A);        // clear the count regs
    outb(0, BASE_NE2K_PORT + 0x0B);
    outb(0, BASE_NE2K_PORT + 0x0F);        // mask completion IRQ
    outb(0xFF, BASE_NE2K_PORT + 0x07);
    outb(0x20, BASE_NE2K_PORT + 0x0C);     // set to monitor
    outb(0x02, BASE_NE2K_PORT + 0x0D);     // and loopback mode.
    outb(32, BASE_NE2K_PORT + 0x0A);       // reading 32 bytes
    outb(0, BASE_NE2K_PORT + 0x0B);        // count high
    outb(0, BASE_NE2K_PORT + 0x08);        // start DMA at 0
    outb(0, BASE_NE2K_PORT + 0x09);        // start DMA high
    outb(0x0A, BASE_NE2K_PORT);            // start the read

    for (i = 0; i < 32; i++) {
        card_data[i] = inb(BASE_NE2K_PORT + 0x10);
        printf("%d", card_data[i]);
    };
}

void ne2k_handler(void) {
    return;
}
