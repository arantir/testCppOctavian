#include "design.h"
#include "drawing.h"
#include "buttons.h"

//Конструктор класса и инииализация всего видимого интерфейса.
Design::Design() {
    // Инициализация GTK
    gtk_init(nullptr, nullptr);

    // Создание нового окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Рисование с GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 500);

    // Создание сетки
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    setup_drawing_areas();
    setup_buttons();

    // Закрытие приложения при закрытии окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

Design::~Design() {
}

void Design::setup_drawing_areas() {
    const char* colors[] = {"синий", "красный", "зелёный", "черный", "синий"};
    const char* shapes[] = {"квадрат", "круг", "квадрат", "звезда", "треугольник"};

    for (int i = 0; i < 5; ++i) {
        drawing_areas[i] = gtk_drawing_area_new();
        gtk_widget_set_size_request(drawing_areas[i], 200, 200);
        gtk_grid_attach(GTK_GRID(grid), drawing_areas[i], i + 1, 2, 1, 1);

        DrawData *data = new DrawData(colors[i], shapes[i]);
        g_signal_connect(G_OBJECT(drawing_areas[i]), "draw", G_CALLBACK(on_draw_event), data);
    }

    space_areas[0] = gtk_drawing_area_new();
    space_areas[1] = gtk_drawing_area_new();
    
    gtk_widget_set_size_request(space_areas[0], 50, 50);
    gtk_widget_set_size_request(space_areas[1], 50, 50);
    
    gtk_grid_attach(GTK_GRID(grid), space_areas[0], 0, 0, 1, 1);
    //gtk_grid_attach(GTK_GRID(grid), space_areas[0], 3, 0, 1, 1);
}

void Design::setup_buttons() {
    buttonStart = gtk_button_new_with_label("Start");
    gtk_grid_attach(GTK_GRID(grid), buttonStart, 6, 1, 1, 1);
    
    buttonStop = gtk_button_new_with_label("Stop");
    gtk_grid_attach(GTK_GRID(grid), buttonStop, 6, 3, 1, 1);

    g_signal_connect(buttonStart, "clicked", G_CALLBACK(on_button_clicked_start), NULL);
    g_signal_connect(buttonStop, "clicked", G_CALLBACK(on_button_clicked_stop), NULL);
}

void Design::show_all() {
   gtk_widget_show_all(window);
}