#include "buttons.h"

// Обработчик нажатия кнопки start
void on_button_clicked_start(GtkWidget *widget, gpointer data) {
    showDialog(widget, "start");
}

// Обработчик нажатия кнопки stop
void on_button_clicked_stop(GtkWidget *widget, gpointer data) {
    showDialog(widget, "stop");
}