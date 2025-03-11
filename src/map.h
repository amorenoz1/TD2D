#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

struct MapDrawable {
   int x;
   int y;
   char type;
};

class Map {
public:
   static void Render();  
   static void Init(std::string map_filepath);
   static bool AddTower(int row, int col);
   static void PrintMap();

private:
   static bool initialized;
   static char** map_buf;
   static int nsize, msize;
   static std::vector<MapDrawable> m_drawable;
};

#endif
