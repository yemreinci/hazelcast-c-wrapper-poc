#include <stdio.h>

#include "hz_wrapper.h"

int main() {

    while (1) {

        char map_name[256], key[256];

        printf("input map and key name: ");
        scanf(" %s %s", map_name, key);

        int val = hazelcast_map_get(map_name, key);

        printf("val = %d\n", val);

    }

    return 0;

}