#include <gtk/gtk.h>

// Функция для рисования
static void do_drawing(cairo_t *cr) {
    // Установите цвет (красный)
    cairo_set_source_rgb(cr, 1, 0, 0);
    // Нарисуйте прямоугольник
    cairo_rectangle(cr, 50, 50, 200, 100);
    cairo_fill(cr);

    // Установите цвет (синий)
    cairo_set_source_rgb(cr, 0, 0, 1);
    // Нарисуйте круг
    cairo_arc(cr, 150, 150, 50, 0, 2 * G_PI);
    cairo_fill(cr);
}

// Обработчик события "рисование"
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    do_drawing(cr);
    return FALSE;
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *drawing_area;

    // Инициализация GTK
    gtk_init(&argc, &argv);

    // Создание нового окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Рисование с GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Создание области для рисования
    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Подключение обработчика события
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);

    // Закрытие приложения при закрытии окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Отображение всех виджетов
    gtk_widget_show_all(window);

    // Запуск основного цикла GTK
    gtk_main();

    return 0;
}
