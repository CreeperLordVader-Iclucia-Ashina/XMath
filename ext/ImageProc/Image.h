#ifndef XMATH_IMAGE_H
#define XMATH_IMAGE_H
#include "../global.h"
#include <iostream>
#include <memory>
#include <utility>
#include <fstream>
#include "../Vector.h"
//the Image class is an abstraction of the image data
namespace ImageProc
{
    template<typename T>
    class Image
    {
        protected:
            uint m = 0, n = 0;
            std::string path;
        public:
            explicit Image(const std::string&  _path) : path(_path) {}
            explicit Image(std::string&&  _path) : path(std::move(_path)) {}
            virtual T pixel(uint, uint) const = 0;
            std::string getPath() const { return path; }
    };
    class Vec3i;
    class PPMImage : Image<Vec3i>
    {
        private:
            //PPM is the simplest format for storing image, so I shall start with this.
            //Later I may add support for JPEG as well?
            enum status{NORMAL, EMPTY, CORRUPT};
            Matrix<int> R, G, B;
        public:
            explicit PPMImage(const std::string&  _path) : Image(_path)
            {
                std::ifstream img;
                img.open(_path);
                img >> m >> n;
                R = Matrix<int>(m, n);
                G = Matrix<int>(m, n);
                B = Matrix<int>(m, n);
                for(int i = 0; i < m; i++)
                    for(int j = 0; j < n; j++)
                        img >> R[i][j] >> G[i][j] >> B[i][j];
            }
            Vec3i pixel(uint, uint) const override;
    };
}
#endif //XMATH_IMAGE_H