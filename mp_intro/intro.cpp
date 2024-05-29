#include "RGB/png.h"
#include "RGB/rgbapixel.h"

#include <string>
#include <cmath>

void rotate(std::string inputFile, std::string outputFile) {
	PNG pic(inputFile);
	
	unsigned int width = pic.width();
    unsigned int height = pic.height();

    PNG rotated(width, height);

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            unsigned int newX = width - x - 1;
            unsigned int newY = height - y - 1;

            *(rotated(newX, newY)) = *(pic(x, y));
        }
    }

	rotated.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
	PNG png(width, height);

    RGBAPixel red(255, 0, 0);
    RGBAPixel green(0, 255, 0);
    RGBAPixel blue(0, 0, 255);

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            double ratio = static_cast<double>(x) / (width - 1);

            RGBAPixel color;
            if (ratio < 0.5) {
                double factor = ratio / 0.5;
                color.red = static_cast<unsigned char>((1 - factor) * red.red + factor * green.red);
                color.green = static_cast<unsigned char>((1 - factor) * red.green + factor * green.green);
                color.blue = static_cast<unsigned char>((1 - factor) * red.blue + factor * green.blue);
            } else {
                double factor = (ratio - 0.5) / 0.5;
                color.red = static_cast<unsigned char>((1 - factor) * green.red + factor * blue.red);
                color.green = static_cast<unsigned char>((1 - factor) * green.green + factor * blue.green);
                color.blue = static_cast<unsigned char>((1 - factor) * green.blue + factor * blue.blue);
            }

            *(png(x, y)) = color;
        }
    }

	return png;
}
