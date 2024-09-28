#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_IPS 1000

typedef struct {
    char ip[MAX_IP_LENGTH];
    int count;
} IPCount;

char* mostFrequentIP(char** ips, int ipsSize) {
    IPCount ipCounts[MAX_IPS] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < ipsSize; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(ips[i], ipCounts[j].ip) == 0) {
                ipCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(ipCounts[uniqueCount].ip, ips[i]);
            ipCounts[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    int maxCount = 0;
    char* mostFrequent = NULL;
    for (int i = 0; i < uniqueCount; i++) {
        if (ipCounts[i].count > maxCount) {
            maxCount = ipCounts[i].count;
            mostFrequent = ipCounts[i].ip;
        }
    }

    return mostFrequent;
}

int main() {
    char* ips[] = {"192.168.1.1", "10.0.0.1", "192.168.1.1", "172.16.0.1", "10.0.0.1", "192.168.1.1"};
    int ipsSize = sizeof(ips) / sizeof(ips[0]);

    char* result = mostFrequentIP(ips, ipsSize);
    printf("Most frequent IP: %s\n", result);

    return 0;
}
