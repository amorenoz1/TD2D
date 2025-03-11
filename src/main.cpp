#include <utils.h>
#include <raylib.h>
#include <map.h>

int main (int argc, char** argv) {

   InitWindow(WIDTH, HEIGHT, TITLE);


   while (!WindowShouldClose()) {
      BeginDrawing();

      EndDrawing();
   }

   CloseWindow();
   return 0;
}
