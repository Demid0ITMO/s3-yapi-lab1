#ifndef IMAGE_TRANSFORMER_IMAGE_H

#include <stdint.h>

#pragma pack(push, 1)

struct pixel { uint8_t b, g, r; };

struct image {
    uint32_t width;
    uint32_t height;
    struct pixel* data;
};

#pragma pack(pop)

#define IMAGE_TRANSFORMER_IMAGE_H

#endif 
