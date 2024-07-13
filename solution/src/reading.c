#include "reading.h"
#include <stdio.h>

enum read_status file_read(char *string, struct image* image, bool (convert_to_type) (FILE*, struct image*)) {
    FILE* fo = fopen(string, "r");
    if (fo == NULL) return CANNOT_FIND_FILE;
    else if (convert_to_type(fo, image)) return READ_OK;
    else return READ_CONVERT_ERROR;
}
