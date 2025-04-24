#include <gtk/gtk.h>
#include "design.h"

int main(int argc, char *argv[]) {
   Design design;
   design.show_all();

   // Запуск основного цикла GTK
   gtk_main();

   return 0;
}