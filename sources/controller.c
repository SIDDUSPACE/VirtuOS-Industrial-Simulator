#include <stdio.h>
#include <unistd.h>

int main() {
    float t, l;
    printf("--- VirtuOS Industrial Control System ---\n");
    
    while(1) {
        FILE *ft = fopen("/tmp/sensor_temp", "r");
        FILE *fl = fopen("/tmp/sensor_load", "r");
        
        if (ft && fl) {
            fscanf(ft, "%f", &t);
            fscanf(fl, "%f", &l);
            fclose(ft); fclose(fl);

            printf("\r[TEMP: %.1f C] [LOAD: %.2f] | STATUS: ", t, l);
            
            if (t > 50.0 || l > 0.50) 
                printf("!! OVERHEAT/OVERLOAD !! ");
            else 
                printf("SYSTEM NOMINAL      ");
            
            fflush(stdout);
        }
        usleep(500000);
    }
    return 0;
}
