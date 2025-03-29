#include "drawing.h"

// Функция для рисования
void do_drawing(cairo_t *cr, const std::string& color, const std::string& figure) {
    // Устанавливаем цвет фигуры.
    if (color == "красный") {
        cairo_set_source_rgb(cr, 1, 0, 0);
    } else if (color == "синий") {
        cairo_set_source_rgb(cr, 0, 0, 1);
    } else if (color == "зелёный") {
        cairo_set_source_rgb(cr, 0, 1, 0);
    } else if (color == "черный") {
        cairo_set_source_rgb(cr, 0, 0, 0);
    }

    // Устанавливаем тип фигуры.
    if (figure == "треугольник") {
        cairo_move_to(cr, 100, 50); // Вершина 1
        cairo_line_to(cr, 50, 150); // Вершина 2
        cairo_line_to(cr, 150, 150); // Вершина 3
        cairo_close_path(cr); // Замыкаем путь
    } else if (figure == "круг") {
        cairo_arc(cr, 100, 100, 50, 0, 2 * G_PI);
    } else if (figure == "квадрат") {
        cairo_rectangle(cr, 50, 50, 50, 50);
    } else if (figure == "звезда") {
        cairo_move_to(cr, 100, 10); // Вершина 1
        cairo_line_to(cr, 120, 80); // Вершина 2
        cairo_line_to(cr, 190, 80); // Вершина 3
        cairo_line_to(cr, 130, 130); // Вершина 4
        cairo_line_to(cr, 150, 200); // Вершина 5
        cairo_line_to(cr, 100, 160); // Вершина 6
        cairo_line_to(cr, 50, 200); // Вершина 7
        cairo_line_to(cr, 70, 130); // Вершина 8
        cairo_line_to(cr, 10, 80); // Вершина 9
        cairo_line_to(cr, 80, 80); // Вершина 10
        cairo_close_path(cr); // Замыкаем путь
    }
    cairo_fill(cr);
}

// Обработчик события "рисование"
gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    // Приводим gpointer к Вашему классу DrawData
    DrawData *data = static_cast<DrawData*>(user_data);
    do_drawing(cr, data->color, data->shape);
    return FALSE;
}
