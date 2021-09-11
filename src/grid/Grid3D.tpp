namespace JUtils
{
    template <class T>
    Grid3D<T>::Grid3D(int width, int height, int depth)
    {
        this->width = width;
        this->height = height;
        this->depth = depth;

        this->grid = (T*) malloc(sizeof(T) * width * height * depth); // Allocate grid
    }

    template <class T>
    T* Grid3D<T>::get(int x, int y, int z)
    {
        if (x > this->width  || x < 0)
            return 0;
        if (y > this->height || y < 0)
            return 0;
        if (z > this->width  || z < 0)
            return 0;

        return &this->grid[(y * this->width + x) + (z * this->width * this->height)];
    }

    template <class T>
    void Grid3D<T>::set(int x, int y, int z, T data)
    {
        if (x > this->width  || x < 0)
            return;
        if (y > this->height || y < 0)
            return;
        if (z > this->width  || z < 0)
            return;

        this->grid[(y * this->width + x) + (z * this->width * this->height)] = data;
    }

    template <class T>
    T* Grid3D<T>::getGrid()
    {
        return this->grid;
    }

    template <class T>
    int Grid3D<T>::getWidth()
    {
        return this->width;
    }

    template <class T>
    int Grid3D<T>::getHeight()
    {
        return this->height;
    }

    template <class T>
    int Grid3D<T>::getDepth()
    {
        return this->depth;
    }
}