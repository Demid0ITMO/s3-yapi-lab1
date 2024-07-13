#ifndef IMAGE_TRANSFORMER_BMP_H

#include "image.h"
#include <bits/types/FILE.h>
#include <stdbool.h>

#pragma pack(push, 1)

struct bmp_header {
    uint16_t bf_type;
    uint32_t b_file_size;
    uint32_t bf_reserved;
    uint32_t b_off_bits;
    uint32_t bi_size;
    uint32_t bi_width;
    uint32_t bi_height;
    uint16_t bi_planes;
    uint16_t bi_bit_count;
    uint32_t bi_compression;
    uint32_t bi_size_image;
    uint32_t bi_x_pels_per_meter;
    uint32_t bi_y_pels_per_meter;
    uint32_t bi_clr_used;
    uint32_t bi_clr_important;
};

struct bmp_file {
    struct bmp_header header;
    uint8_t* data;
};

#pragma pack(pop)


bool from_bmp_to_image(FILE* in, struct image* image);
bool from_image_to_bmp(FILE* out, const struct image* image);

#define IMAGE_TRANSFORMER_BMP_H

#endif 
