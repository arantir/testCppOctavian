#include <gtk/gtk.h>
#include <string>
#include "structs.h"
#include "drawing.h"
#include "buttons.h"

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *drawing_area1, *drawing_area2, *drawing_area3, *drawing_area4, *drawing_area5;
    GtkWidget *space_area1, *space_area2;
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
    space_area1 = gtk_drawing_area_new();
    space_area2 = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area1, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area2, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area3, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area4, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(drawing_area5, 200, 200); // Установка размера области рисования
    gtk_widget_set_size_request(space_area1, 100, 100); // Установка размера области
    gtk_widget_set_size_request(space_area2, 100, 100); // Установка размера области
    gtk_grid_attach(GTK_GRID(grid), drawing_area1, 0, 2, 1, 1); // Вставка в 3-ю строку и 1-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area2, 1, 2, 1, 1); // Вставка в 3-ю строку и 2-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area3, 2, 2, 1, 1); // Вставка в 3-ю строку и 3-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area4, 3, 2, 1, 1); // Вставка в 3-ю строку и 4-й столбец
    gtk_grid_attach(GTK_GRID(grid), drawing_area5, 4, 2, 1, 1); // Вставка в 3-ю строку и 5-й столбец
    gtk_grid_attach(GTK_GRID(grid), space_area1, 0, 0, 1, 1); // Вставка в 1-ю строку и 1-й столбец
    gtk_grid_attach(GTK_GRID(grid), space_area2, 4, 0, 1, 1); // Вставка в 5-ю строку и 1-й столбец

    // Создание drawing_area и установка обработчиков
	DrawData *data1 = new DrawData("синий", "квадрат");
	DrawData *data2 = new DrawData("красный", "круг");
	DrawData *data3 = new DrawData("зелёный", "квадрат");
	DrawData *data4 = new DrawData("черный", "звезда");
	DrawData *data5 = new DrawData("синий", "треугольник");
	g_signal_connect(G_OBJECT(drawing_area1), "draw", G_CALLBACK(on_draw_event), data1);
	g_signal_connect(G_OBJECT(drawing_area2), "draw", G_CALLBACK(on_draw_event), data2);
	g_signal_connect(G_OBJECT(drawing_area3), "draw", G_CALLBACK(on_draw_event), data3);
	g_signal_connect(G_OBJECT(drawing_area4), "draw", G_CALLBACK(on_draw_event), data4);
	g_signal_connect(G_OBJECT(drawing_area5), "draw", G_CALLBACK(on_draw_event), data5);

    // Создание кнопок
    buttonStart = gtk_button_new_with_label("Start");
    gtk_grid_attach(GTK_GRID(grid), buttonStart, 5, 1, 1, 1); // 6-й столбец, 2-я строка
    buttonStop = gtk_button_new_with_label("Stop");
    gtk_grid_attach(GTK_GRID(grid), buttonStop, 5, 3, 1, 1); // 6-й столбец, 4-я строка

    // Подключение обработчиков нажатия кнопок
    g_signal_connect(buttonStart, "clicked", G_CALLBACK(on_button_clicked_start), NULL);
    g_signal_connect(buttonStop, "clicked", G_CALLBACK(on_button_clicked_stop), NULL);

    // Закрытие приложения при закрытии окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Отображение всех виджетов
    gtk_widget_show_all(window);

    // Запуск основного цикла GTK
    gtk_main();

	delete data1;
	delete data2;
	delete data3;
	delete data4;
	delete data5;
    return 0;
}
