#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  // Check if the user typed in any arguments.
  if (argc < 2) {
    printf("Usage: draw_shapes <shape> <color>\n");
    exit(1);
  }

  // Get the shape that the user wants to draw.
  const char *shape = argv[1];

  // Get the color of the shape that the user wants.
  const char *color = argv[2];

  // Draw the shape.
  if (strcmp(shape, "square") == 0) {
    printf("Drawing a %s square.\n", color);
  } else if (strcmp(shape, "circle") == 0) {
    printf("Drawing a %s circle.\n", color);
  } else {
    printf("Unknown shape: %s\n", shape);
    exit(1);
  }

  return 0;
}
