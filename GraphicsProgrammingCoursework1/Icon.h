#ifndef _ICON_H
#define _ICON_H

struct Icon
{
	unsigned int 	 width;
	unsigned int 	 height;
	unsigned int 	 bytes_per_pixel;
	unsigned char	 pixel_data[64 * 64 * 4 + 1];
};

#endif