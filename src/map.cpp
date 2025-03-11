#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map.h>
#include <raylib.h>
#include <string>
#include <utils.h>

int Map::msize = 0;
int Map::nsize = 0;
bool Map::initialized = false;
char **Map::map_buf = nullptr;
std::vector<MapDrawable> Map::m_drawable = {};

void Map::Init(std::string map_filepath) {
   std::fstream file(map_filepath);

   if (!file) {
      std::cerr << "Error: Error opening file containing map!";
      exit(1);
   }

   std::string line;

   // get dimensions
   std::getline(file, line);
   nsize = atoi(line.c_str());

   std::getline(file, line);
   msize = atoi(line.c_str());

   // initialize map_buf
   map_buf = new char *[nsize];

   for (int i = 0; i < msize; i++) {
      map_buf[i] = new char[msize];
   }

   // reading map from file.
   int i = 0;
   while (std::getline(file, line) && i < nsize) {
      for (int j = 0; j < msize; j++) {
         map_buf[i][j] = line.c_str()[j];
         if (map_buf[i][j] == 'E' || map_buf[i][j] == 'p' || map_buf[i][j] == 'S') {
            MapDrawable drawable = {.x = i, .y = j, .type = map_buf[i][j]};
            m_drawable.push_back(drawable);
         }
      }
      i++;
   }

   PrintMap();
}

void Map::Render() {
   Vector2 size = {
      600 / (float) nsize,
      600 / (float) msize
   };

   for (MapDrawable obj : m_drawable) {
      Vector2 position = {
         (size.y * obj.y) + 100,
         (size.x * obj.x)
      };

      Color color;
      switch (obj.type) {
         case 'E':
            color = COLP_DARKGREEN;
            break;
         case 'p':
            color = COLP_DARKGRAY;
            break;
         case 'S':
            color = COLP_DARKRED;
            break;
      }

      DrawRectangleV(position, size, color);
   }
}

bool Map::AddTower(int row, int col) {
   if (map_buf[row][col] == '.') {
      map_buf[row][col] = 't';
      return true;
   }
   return false;
}

void Map::PrintMap() {
   for (int i = 0; i < nsize; i++) {
      for (int j = 0; j < msize; j ++) {
         std::cout << map_buf[i][j];
      }
      std::cout << std::endl;
   }

   for (MapDrawable obj : m_drawable) {
      std::cout << obj.type << " ";
   }
   std::cout << std::endl;
}
