#ifndef IMAGE_TRANSFORMER_WRITING_H

#include "image.h"
#include <bits/types/FILE.h>
#include <stdbool.h>

enum write_status {
    WRITE_OK = 0,
    WRITE_CONVERT_ERROR,
    ANOTHER_WRITING_ERROR
};

enum write_status file_write(char *string, const struct image* image, bool (convert_to_type) (FILE*, const struct image*));

#define IMAGE_TRANSFORMER_WRITING_H

#endif 
