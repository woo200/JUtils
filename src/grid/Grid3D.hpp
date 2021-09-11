#pragma once

#include <stdlib.h>

namespace JUtils
{
    template <class T>
    class Grid3D
    {
        int width, height, depth;
        T* grid;
    public:
        Grid3D(int width, int height, int depth);
        
        T* getGrid();

        T* get(int x, int y, int z);
        void set(int x, int y, int z, T);

        int getWidth();
        int getHeight();
        int getDepth();
    };
}

#include "Grid3D.tpp"