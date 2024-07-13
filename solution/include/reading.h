#ifndef IMAGE_TRANSFORMER_READING_H

#include "image.h"
#include <bits/types/FILE.h>
#include <stdbool.h>

enum read_status {
    READ_OK = 0,
    READ_CONVERT_ERROR,
    CANNOT_FIND_FILE,
    ANOTHER_READING_ERROR
};
enum read_status file_read(char *string, struct image* image, bool (convert_to_type) (FILE*, struct image*));


#define IMAGE_TRANSFORMER_READING_H

#endif 
