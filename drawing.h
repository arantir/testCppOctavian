#ifndef DRAWING_H
#define DRAWING_H

#include <gtk/gtk.h>
#include <string>
#include "structs.h" // Подключаем файл с определением структуры

// Функция для рисования
void do_drawing(cairo_t *cr, const std::string& color, const std::string& figure);

// Обработчик события "рисование"
gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

#endif // DRAWING_H
