#include "collector.h"
#include "droplet.h"
#include "mesh.h"

void collector_init(void) {
    droplet_sensor_init();
    mesh_bias_enable();
}

uint32_t collector_yield_ml(void) {
    uint32_t droplets = droplet_count_take();
    return droplet_volume_ul(droplets) / 1000U;
}
