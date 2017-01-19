/* GIMP RGBA C-Source image dump (ZeroButton.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[20 * 20 * 4 + 1];
} zeroButton_img = {
  20, 20, 4,
  "\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255"
  "\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377"
  "\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255"
  "\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377"
  "\255\255\255\377\255\255\255\377\255\255\255\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255"
  "\255\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\255\255\255\377\255\255\255\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255\255\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\255\255\255\377\255\255\255\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255"
  "\255\377\377\377\377\377\377\377\377\377\377\377\377\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\255\255\255\377\255\255\255\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\312\312\312"
  "\377\344\344\344\377\314\314\314\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\255"
  "\255\255\377\255\255\255\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\325\325\325\377\363\363\363"
  "\377\336\336\336\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\255\255\255\377\255"
  "\255\255\377\377\377\377\377\377\377\377\377\377\377\377\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\331\331\331\377\360\360\360\377\342\342\342"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255\255\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\333\333\333\377\355\355\355\377\341\341\341\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\255\255\255\377\255\255\255\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\334\334"
  "\334\377\352\352\352\377\342\342\342\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\255\255\255\377\255\255\255\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\331\331\331\377\350\350"
  "\350\377\337\337\337\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\255\255\255\377"
  "\255\255\255\377\377\377\377\377\377\377\377\377\377\377\377\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\322\322\322\377\337\337\337\377\330\330\330"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255\255\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\255\255\255\377\255\255\255\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255"
  "\255\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\255\255\255\377\255\255\255\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\255\255\255\377\255\255\255\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255"
  "\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377"
  "\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255"
  "\255\377\255\255\255\377\255\255\255\377\255\255\255\377\255\255\255\377"
  "\255\255\255\377\255\255\255\377\255\255\255\377",
};
