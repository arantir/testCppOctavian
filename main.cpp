#include <gtk/gtk.h>

// Функция для рисования
static void do_drawing(cairo_t *cr) {
    // Установите цвет (красный)
    cairo_set_source_rgb(cr, 1, 0, 0);
    // Нарисуйте прямоугольник
    cairo_rectangle(cr, 50, 50, 100, 50);
    cairo_fill(cr);
}

// Функция для рисования
static void do_drawing2(cairo_t *cr) {
    // Установите цвет (синий)
    cairo_set_source_rgb(cr, 0, 0, 1);
    // Нарисуйте круг
    cairo_arc(cr, 100, 100, 50, 0, 2 * G_PI);
    cairo_fill(cr);
}

// Обработчик события "рисование"
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    do_drawing(cr);
    return FALSE;
}

// Обработчик события "рисование"
static gboolean on_draw_event2(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    do_drawing2(cr);
    return FALSE;
}

// Обработчик нажатия кнопки
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(data),
                                     GTK_DIALOG_MODAL,
                                     GTK_MESSAGE_INFO,
                                     GTK_BUTTONS_OK,
                                     "Кнопка нажата!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *drawing_area;
    GtkWidget *drawing_area2;
    GtkWidget *button;

    // Инициализация GTK
    gtk_init(&argc, &argv);

    // Создание нового окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Рисование с GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 300);

    // Создание сетки
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Создание области для рисования
    drawing_area = gtk_drawing_area_new();
    drawing_area2 = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area2, 200, 200); // Установка размера области рисования
    gtk_grid_attach(GTK_GRID(grid), drawing_area, 1, 1, 1, 1); // Вставка в 2-ю строку и 2-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area2, 2, 1, 1, 1); // Вставка в 2-ю строку и 3-й столбец

    // Подключение обработчика события
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(G_OBJECT(drawing_area2), "draw", G_CALLBACK(on_draw_event2), NULL);

    // Создание кнопки
    button = gtk_button_new_with_label("Нажми меня");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1); // Вставка в 5-ю строку и 3-й столбец

    // Подключение обработчика нажатия кнопки
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Закрытие приложения при закрытии окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Отображение всех виджетов
    gtk_widget_show_all(window);

    // Запуск основного цикла GTK
    gtk_main();

    return 0;
}
