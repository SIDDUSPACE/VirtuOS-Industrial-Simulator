#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

float get_system_stats() {
    FILE *memfile = fopen("/proc/meminfo", "r");
    FILE *loadfile = fopen("/proc/loadavg", "r");
    FILE *uptimefile = fopen("/proc/uptime", "r");
    
    char line[256];
    long memTotal = 0, memFree = 0;
    float load = 0.0;
    float uptime = 0.0;

    if (memfile) {
        while (fgets(line, sizeof(line), memfile)) {
            if (strncmp(line, "MemTotal:", 9) == 0) sscanf(line, "MemTotal: %ld", &memTotal);
            if (strncmp(line, "MemFree:", 8) == 0) sscanf(line, "MemFree: %ld", &memFree);
        }
        fclose(memfile);
    }
    if (loadfile) {
        fscanf(loadfile, "%f", &load);
        fclose(loadfile);
    }
    if (uptimefile) {
        fscanf(uptimefile, "%f", &uptime);
        fclose(uptimefile);
    }

    long memUsed = (memTotal - memFree) / 1024;
    printf("[VirtuOS Health]: Uptime: %.0fs | Mem Used: %ldMB | CPU Load: %.2f\n", uptime, memUsed, load);
    
    return load; // Return the load so main() can use it
}

int main() {
    while (1) {
        float current_load = get_system_stats();
        
        // --- VIRTUAL LED LOGIC ---
        FILE *led_file = fopen("/tmp/virtual_led", "w");
        if (led_file) {
            // If CPU load is higher than 0.10, send "1" (LED ON), else "0" (OFF)
            if (current_load > 0.10) {
                fprintf(led_file, "1");
            } else {
                fprintf(led_file, "0");
            }
            fclose(led_file);
        }
        
        sleep(2); 
    }
    return 0;
}
