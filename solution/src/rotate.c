#include "rotate_transform.h"
#include "util.h"
#include <malloc.h>

static void simple_90_degrees_rotate(struct image* old_image, struct image* new_image) {
    new_image->height = old_image->width;
    new_image->width = old_image->height;
    size_t count = 0;
    for (size_t i = 0; i < old_image->width; i++) {
    	for (size_t j = 0; j < old_image->height; j++) {
    		new_image->data[count] = (struct pixel) {
    			.r = old_image->data[(old_image->height - 1 - j) * old_image->width + i].r,
    			.g = old_image->data[(old_image->height - 1 - j) * old_image->width + i].g,
    			.b = old_image->data[(old_image->height - 1 - j) * old_image->width + i].b
    		};
    		count++;
    	}
    }
}

void rotate(struct image* old_image, struct image* new_image, int64_t pi_count) {
    if (pi_count > 0) pi_count = pi_count % 4;
    else pi_count = padding(-pi_count);    
    for (size_t i = 0; i < pi_count; i++) {
    	simple_90_degrees_rotate(old_image, new_image);
    	copy_data(new_image, old_image);
    }
}
