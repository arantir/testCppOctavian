#include <gtk/gtk.h>
#include <string>
#include <memory>

using namespace std;

// Структура для хранения данных
struct DrawData {
    string color;
    string shape;
    // Конструктор
    DrawData(const string& c, const string& s) : color(c), shape(s) {}
};

// Функция для создания объекта DrawData
shared_ptr<DrawData> create_draw_data(const string& color, const string& shape) {
    return make_shared<DrawData>(color, shape);
}

// Функция для рисования
static void do_drawing(cairo_t *cr, string color, string figure) {
	//Устанавливаем цвет фигуры.
	if (color == "красный")
	{
		cairo_set_source_rgb(cr, 1, 0, 0);
	}
	if (color == "синий")
	{
		cairo_set_source_rgb(cr, 0, 0, 1);
	}
	if (color == "зелёный")
	{
		cairo_set_source_rgb(cr, 0, 1, 0);
	}
	if (color == "черный")
	{
		cairo_set_source_rgb(cr, 0, 0, 0);
	}
	//Устанавливаем тип фигуры.
	if (figure == "треугольник")
	{
		cairo_move_to(cr, 100, 50); // Вершина 1
		cairo_line_to(cr, 50, 150); // Вершина 2
		cairo_line_to(cr, 150, 150); // Вершина 3
		cairo_close_path(cr); // Замыкаем путь
	}
	if (figure == "круг")
	{
		cairo_arc(cr, 100, 100, 50, 0, 2 * G_PI);
	}
	if (figure == "квадрат")
	{
		cairo_rectangle(cr, 50, 50, 50, 50);
	}
	if (figure == "звезда")
	{
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
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    auto data = static_cast<shared_ptr<DrawData>>(user_data);
    do_drawing(cr, data->color.c_str(), data->shape.c_str());
    return FALSE; // Не освобождаем память здесь, так как используем shared_ptr
}

// Обработчик нажатия кнопки
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *button_name = (const gchar *)data;

    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                     GTK_DIALOG_MODAL,
                                     GTK_MESSAGE_INFO,
                                     GTK_BUTTONS_OK,
                                     "%s", button_name);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Пример подключения обработчиков
void setup_drawing_area(GtkWidget *drawing_area, const std::string& color, const std::string& shape) {
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), create_draw_data(color, shape).get());
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *drawing_area1, *drawing_area2, *drawing_area3, *drawing_area4, *drawing_area5;
    GtkWidget *buttonStart, *buttonStop;

    // Инициализация GTK
    gtk_init(&argc, &argv);

    // Создание нового окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Рисование с GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 500);

    // Создание сетки
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Создание области для рисования
    drawing_area1 = gtk_drawing_area_new();
    drawing_area2 = gtk_drawing_area_new();
    drawing_area3 = gtk_drawing_area_new();
    drawing_area4 = gtk_drawing_area_new();
    drawing_area5 = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area1, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area2, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area3, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area4, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area5, 200, 200); // Установка размера области рисования
    gtk_grid_attach(GTK_GRID(grid), drawing_area1, 0, 2, 1, 1); // Вставка в 3-ю строку и 1-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area2, 1, 2, 1, 1); // Вставка в 3-ю строку и 2-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area3, 2, 2, 1, 1); // Вставка в 3-ю строку и 3-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area4, 3, 2, 1, 1); // Вставка в 3-ю строку и 4-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area5, 4, 2, 1, 1); // Вставка в 3-ю строку и 5-й столбец

    // Создание drawing_area и установка обработчиков
    setup_drawing_area(drawing_area1, "синий", "квадрат");
    setup_drawing_area(drawing_area2, "красный", "круг");
    setup_drawing_area(drawing_area3, "зелёный", "квадрат");
    setup_drawing_area(drawing_area4, "черный", "звезда");
    setup_drawing_area(drawing_area5, "синий", "треугольник");

    // Создание кнопок
    buttonStart = gtk_button_new_with_label("Start");
    gtk_grid_attach(GTK_GRID(grid), buttonStart, 5, 1, 1, 1); // 6-й столбец, 2-я строка
    buttonStop = gtk_button_new_with_label("Stop");
    gtk_grid_attach(GTK_GRID(grid), buttonStop, 5, 3, 1, 1); // 6-й столбец, 4-я строка

    // Подключение обработчиков нажатия кнопок
    g_signal_connect(buttonStart, "clicked", G_CALLBACK(on_button_clicked), (gpointer)"Start");
    g_signal_connect(buttonStop, "clicked", G_CALLBACK(on_button_clicked), (gpointer)"Stop");

    // Закрытие приложения при закрытии окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Отображение всех виджетов
    gtk_widget_show_all(window);

    // Запуск основного цикла GTK
    gtk_main();

    return 0;
}
