#include <stdio.h>
#include <linux/fb.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#define clear() printf("\033[H\033[J")

int main()
{
	clear();
	int fbfd = open ("/dev/fb0", O_RDWR);
	if (fbfd >= 0)
	{
		struct fb_var_screeninfo vinfo;

		ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo);

		int fb_width = vinfo.xres;
		int fb_height = vinfo.yres;
		int fb_bpp = vinfo.bits_per_pixel;
		int fb_bytes = fb_bpp / 8;

		int fb_data_size = fb_width * fb_height * fb_bytes;

		char *fbdata = mmap (0, fb_data_size,
				PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, (off_t)0);

		while (1)
			for (int frame = 0; frame < 250; frame += 1)
			{
				for (int y = 0; y < fb_height; y++)
					for (int x = 0; x < fb_width; x++) {
						fbdata[(y * fb_width + x) * 4 + 0] = 127 * y / fb_height;	//B
						fbdata[(y * fb_width + x) * 4 + 1] = fb_width - (127 * x / fb_width);	//G
						fbdata[(y * fb_width + x) * 4 + 2] = 127 * x / fb_width;	//R
						fbdata[(y * fb_width + x) * 4 + 3] = 0;	//Alpha doesnt make a difference
						/* fbdata[(y * fb_width + x) * 4 + 0] = 0;	//B */
						/* fbdata[(y * fb_width + x) * 4 + 1] = 0;	//G */
						/* fbdata[(y * fb_width + x) * 4 + 2] = 0;	//R */
						/* fbdata[(y * fb_width + x) * 4 + 3] = 127 * x / fb_width;	//A */
					}
				usleep(10);
				printf(" ");
				fflush(stdout);
				printf("\r");
			}
		munmap (fbdata, fb_data_size);
		close (fbfd);
	}
}
