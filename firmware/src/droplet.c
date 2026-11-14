#include "droplet.h"

static volatile uint32_t droplet_events;

void droplet_isr(void) {
    droplet_events++;
}

uint32_t droplet_count_take(void) {
    uint32_t value = droplet_events;
    droplet_events = 0;
    return value;
}

float droplet_volume_ul(uint32_t droplets) {
    return droplets * DROPLET_UL_NOMINAL;
}
