#include "bmp.h"
#include "image.h"
#include "reading.h"
#include "rotate_transform.h"
#include "util.h"
#include "writing.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv ) {
    if (argc < 3) return 2;
    
    struct image old_image;
    
    enum read_status const read_ans = file_read(argv[1], &old_image, from_bmp_to_image);
    if (read_ans != READ_OK) {
    	return read_ans;
    }
    
    struct image new_image;
    struct pixel data[old_image.width*old_image.height];
	new_image.data = data;
	
    copy_data(&old_image, &new_image);
    
    rotate(&old_image, &new_image, -1);
    
    enum write_status const write_ans = file_write(argv[2], &new_image, from_image_to_bmp);
    if (write_ans != WRITE_OK) {
        return write_ans;
    }
	free(old_image.data);
    return 0;
}

