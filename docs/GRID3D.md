# JUtils Grid3D

JUtils Grid3D is a template for creating extremely simple and easy to use 3D grids in memory.

### Usage
Example creating a 10x10x10 grid, setting a few points and printing those points again
```cpp
JUtils::Grid3D<char> grid(10, 10, 10); // Width, Height, Depth

grid.set(0, 0, 0, 'a');
grid.set(0, 0, 1, 'b');
grid.set(1, 0, 0, 'c');

std::cout << *grid.get(0, 0, 0); // Print DEREFERENCED variable because grid.get returns a pointer
std::cout << *grid.get(0, 0, 1);
std::cout << *grid.get(1, 0, 0);
```

Note: If you try to set or get a point that is out of bounds, then it will return a null pointer. Please always check for a null pointer before preforming operations on data pulled from a grid.