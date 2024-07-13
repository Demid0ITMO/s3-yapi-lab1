#include "bmp.h"
#include "util.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

const uint16_t BF_TYPE = 19778;
const uint32_t BI_SIZE = 40;
const uint16_t BI_PLANES = 1;
const uint16_t BI_BIT_COUNT = 24;


bool from_bmp_to_image(FILE* in, struct image* image) {
    struct bmp_file file;
    fread(&file.header, sizeof(struct bmp_header), 1, in);
    file.data = (uint8_t*) malloc(file.header.bi_size_image);

    int64_t bytes_per_pixel = file.header.bi_bit_count/8;
    int64_t row_size = bytes_per_pixel*file.header.bi_width;
    int64_t padd = padding(row_size);
    int64_t rows_written = 0;
    uint8_t* row = (uint8_t*) malloc(row_size + padd);
    uint8_t* p = &file.data[(file.header.bi_height - 1) * row_size];

    fseek(in, file.header.b_off_bits, SEEK_SET);
    while (rows_written < file.header.bi_height) {
    	fread(row, row_size + padd, 1, in);
        if (bytes_per_pixel == 3) {
            for(size_t i = 0; i < row_size; i += bytes_per_pixel) {
                *p = row[i]; p++;
                *p = row[i+1]; p++;
                *p = row[i+2]; p++;
            }
        }
        else {
        	free(file.data);
        	free(row);
        	return false;
        }
        rows_written++;
        p = p - 2 * row_size;
    }

    image->width = file.header.bi_width;
    image->height = file.header.bi_height;
    image->data = (struct pixel *) file.data;

    free(row);

    return true;
}


bool from_image_to_bmp(FILE* out, const struct image* image) {
    struct bmp_file file = {
        .header = {
            .bf_type = BF_TYPE,
            .b_file_size = sizeof(struct bmp_header) + image->height * image->width,
            .b_off_bits = sizeof(struct bmp_header),
            .bi_size = BI_SIZE,
            .bi_width = image->width,
            .bi_height = image->height,
            .bi_planes = BI_PLANES,
            .bi_bit_count = BI_BIT_COUNT,
            .bi_size_image = image->height * image->width
        }
    };
    int64_t bytes_per_pixel = file.header.bi_bit_count / 8;
    
    fwrite(&(file.header), sizeof(struct bmp_header), 1, out);
    
    if (out == NULL) return false;
    
    for (size_t i = 0; i < image->height; i++) {	
    	fwrite(&(image->data[(image->height - 1 - i) * image->width]), image->width, 3, out); 
        fwrite("0000", padding(image->width * bytes_per_pixel) , 1, out);
    }
    return true;
}

