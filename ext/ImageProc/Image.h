#ifndef XMATH_IMAGE_H
#define XMATH_IMAGE_H
#include "../global.h"
#include <iostream>
#include <memory>
#include <utility>
#include <fstream>
#include "../Vector.h"
#include "../../src/Matrix.h"
//the Image class is an abstraction of the image data
namespace ImageProc
{
    using ext::Vec3i;
    using xmath::Matrix;
    template<typename T>
    class Image
    {
        protected:
            enum Format{P1, P2, P3, P4, P5, P6} format;
            uint m = 0, n = 0;
            std::string path;
        public:
            explicit Image(const std::string&  _path) : path(_path) {}
            explicit Image(std::string&&  _path) : path(std::move(_path)) {}
            virtual T pixel(uint, uint) const = 0;
            std::string getPath() const { return path; }
    };
    using ext::Vec3i;
    class PPMImage : Image<Vec3i>
    {
        private:
            //PPM is the simplest format for storing image, so I shall start with this.
            //Later I may add support for JPEG as well?
            Matrix<int> R, G, B;
        public:
            explicit PPMImage(const std::string&  _path) : Image(_path)
            {
                std::ifstream img;
                img.open(_path);
                std::string fmt;
                img >> fmt;
                if(fmt == "P1")
                    format = P1;
                else if(fmt == "P3") format = P3;
                else
                {
                    std::cerr << "WARNING: Image format not supported by PPMImage. Loading failed." << std::endl;
                    return ;
                }
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