#include "util.h"
#include <stddef.h>

void copy_data(struct image* old_image, struct image* new_image) {
	new_image->height = old_image->height;
	new_image->width = old_image->width;
	for (size_t i = 0; i < old_image->height*old_image->width; i++) {
		new_image->data[i] = (struct pixel) { 
		.r = old_image->data[i].r,
		.g = old_image->data[i].g,
		.b = old_image->data[i].b
		};
	}
}

int64_t padding(int64_t x) { return (4 - x % 4) % 4; }
