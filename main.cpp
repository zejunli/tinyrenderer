#include "tgaimage.h"
#include <algorithm>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color) {
    for (float t = 0.0; t <= 1.0; t += 0.01) {
        float x = x0 + (x1 - x0) * t;
        float y = y0 + (y1 - y0) * t;
        image.set(x, y, color);
    }
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    line(50, 50, 80, 80, image, red);
    image.write_tga_file("output.tga");
    return 0;
}