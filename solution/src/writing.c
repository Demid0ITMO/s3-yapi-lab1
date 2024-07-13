#include "writing.h"
#include <stdio.h>

enum write_status file_write(char *string, const struct image* image, bool (convert_to_type) (FILE*, const struct image*)) {
    FILE* fo = fopen(string, "w");
    if (fo == NULL) return ANOTHER_WRITING_ERROR;
    if (convert_to_type(fo, image)) return WRITE_OK;
    return WRITE_CONVERT_ERROR;
}
