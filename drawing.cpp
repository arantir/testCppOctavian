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

    // Устанавливаем размер фигуры
    const double size = 100; // Размер для всех фигур

    // Вычисляем смещение для центрирования
    double offsetX = (200 - size) / 2; // Смещение по X
    double offsetY = (200 - size) / 2; // Смещение по Y

    // Устанавливаем тип фигуры.
    if (figure == "треугольник") {
        cairo_move_to(cr, offsetX + size / 2, offsetY); // Вершина 1
        cairo_line_to(cr, offsetX, offsetY + size); // Вершина 2
        cairo_line_to(cr, offsetX + size, offsetY + size); // Вершина 3
        cairo_close_path(cr); // Замыкаем путь
    } else if (figure == "круг") {
		cairo_arc(cr, offsetX + size / 2, offsetY + size / 2, size / 2, 0, 2 * G_PI);
	} else if (figure == "квадрат") {
        cairo_rectangle(cr, offsetX, offsetY, size, size);
    } else if (figure == "звезда") {
        cairo_move_to(cr, offsetX + size / 2, offsetY + size * 0.1); // Вершина 1
        cairo_line_to(cr, offsetX + size * 0.6, offsetY + size * 0.4); // Вершина 2
        cairo_line_to(cr, offsetX + size * 1.0, offsetY + size * 0.4); // Вершина 3
        cairo_line_to(cr, offsetX + size * 0.7, offsetY + size * 0.6); // Вершина 4
        cairo_line_to(cr, offsetX + size * 0.8, offsetY + size * 1.0); // Вершина 5
        cairo_line_to(cr, offsetX + size / 2, offsetY + size * .8); // Вершина 6
        cairo_line_to(cr, offsetX + size * .2, offsetY + size * 1.0); // Вершина 7
        cairo_line_to(cr, offsetX + size * .3, offsetY + size * .6); // Вершина 8
        cairo_line_to(cr, offsetX + size * .0, offsetY + size * .4); // Вершина 9
        cairo_line_to(cr, offsetX + size * .4, offsetY + size * .4); // Вершина 10
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
