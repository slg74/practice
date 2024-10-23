#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *days[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
    };

    for (int i = 0; i < 7; i++) {
        printf("length: %lu day: %s\n", strlen(days[i]), days[i]); 
    }

    return EXIT_SUCCESS;
}

