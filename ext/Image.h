#ifndef XMATH_IMAGE_H
#define XMATH_IMAGE_H
#include "./global.h"
#include <variant>
#include <memory>
//the Image class is an abstraction of the image data
namespace ImageProc
{
    class Image
    {
        private:
            //PPM is the simplest format for storing image, so I shall start with this.
            //Later I may add support for JPEG as well?
            enum format{PPM};
            enum status{NORMAL, EMPTY, CORRUPT};
            std::string path;
            std::variant<std::shared_ptr<Matrix<int> >，int**> data;
        public:

    };
}
#endif //XMATH_IMAGE_H