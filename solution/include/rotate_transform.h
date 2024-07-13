#ifndef IMAGE_TRANSFORMER_ROTATE_TRANSFORM_H

#include "image.h"

void rotate(struct image *old_image, struct image *new_image, int64_t pi_count);

/* pi_count * pi/2 - количество повторов поворота
 * 1 - на 90 градусов по часовой
 * 2 - на 180, 3 - на 270 и т.д
 * */


#define IMAGE_TRANSFORMER_ROTATE_TRANSFORM_H

#endif 
