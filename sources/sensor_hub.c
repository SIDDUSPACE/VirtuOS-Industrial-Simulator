#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void update_sensors() {
    float temp, load;
    
    // Simulate Temperature based on Uptime (mocking heat buildup)
    FILE *up = fopen("/proc/uptime", "r");
    if (up) {
        float uptime;
        fscanf(up, "%f", &uptime);
        fclose(up);
        temp = 35.0 + (uptime / 100.0); // Starts at 35C and rises slowly
    }

    // Simulate Pressure based on System Load
    FILE *ld = fopen("/proc/loadavg", "r");
    if (ld) {
        fscanf(ld, "%f", &load);
        fclose(ld);
    }

    // Write to "Virtual Sensor" files
    FILE *f_temp = fopen("/tmp/sensor_temp", "w");
    if (f_temp) { fprintf(f_temp, "%.2f", temp); fclose(f_temp); }

    FILE *f_pres = fopen("/tmp/sensor_load", "w");
    if (f_pres) { fprintf(f_pres, "%.2f", load); fclose(f_pres); }
}

int main() {
    while (1) {
        update_sensors();
        sleep(1); 
    }
    return 0;
}
