#include <stdio.h>
#include <unistd.h>

int main() {
    printf("--- VirtuOS Hardware Monitor ---\n");
    while(1) {
        FILE *file = fopen("/tmp/virtual_led", "r");
        if (file) {
            char status = fgetc(file);
            fclose(file);
            
            if (status == '1') {
                printf("\rSTATUS: [ ALERT ] CPU LOAD HIGH [●] RED LED   ");
            } else {
                printf("\rSTATUS: [ NORMAL ] CPU LOAD LOW [○] GREEN LED ");
            }
            fflush(stdout); // Keep the line updating in place
        }
        usleep(500000); // Check every 0.5 seconds
    }
    return 0;
}
