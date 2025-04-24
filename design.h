#ifndef DESIGN_H
#define DESIGN_H

#include <gtk/gtk.h>
#include "structs.h"

class Design {
public:
    Design();
    ~Design();
    void create_widgets();
    void show_all();

private:
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *drawing_areas[6];
    GtkWidget *space_areas[2];
    GtkWidget *buttonStart;
    GtkWidget *buttonStop;

    void setup_drawing_areas();
    void setup_buttons();
};

#endif // DESIGN_H