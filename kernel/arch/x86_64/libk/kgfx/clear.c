#include "./vga.h"
#include <libk/kgfx.h>
#include <stdint.h>
#include <x86_64.h>

static volatile uint16_t *terminalBuffer =
    (volatile uint16_t *)(0xb8000 + KERNEL_CODE_OFFSET);

void kgfx_clear(void) {
  for (uint16_t i = 0; i < VGA_WIDTH; i++) {
    for (uint16_t j = 0; j < VGA_HEIGHT; j++) {
      terminalBuffer[getIndexFromPos(i, j)] = 0x0;
    }
  }
}
