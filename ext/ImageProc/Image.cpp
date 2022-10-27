//
// Created by creeper on 22-10-25.
//

#include "./Image.h"
ImageProc::Vec3i ImageProc::PPMImage::pixel(uint u, uint v) const
{
    return {R[u][v], G[u][v], B[u][v]};
}

