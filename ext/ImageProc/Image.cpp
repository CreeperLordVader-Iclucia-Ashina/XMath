//
// Created by creeper on 22-10-25.
//

#include "./Image.h"
namespace ImageProc
{
    Vec3i PPMImage::pixel(uint u, uint v) const { return {R[u][v], G[u][v], B[u][v]}; }
}


