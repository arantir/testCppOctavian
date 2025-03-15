#include <gtk/gtk.h>

// Функция для обработки нажатия кнопки
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;

    // Создание диалогового окна с сообщением
    dialog = gtk_message_dialog_new(GTK_WINDOW(data),
                                     GTK_DIALOG_DESTROY_WITH_PARENT,
                                     GTK_MESSAGE_INFO,
                                     GTK_BUTTONS_OK,
                                     "Привет, мир!");
    gtk_dialog_run(GTK_DIALOG(dialog)); // Отображение диалогового окна
    gtk_widget_destroy(dialog); // Уничтожение диалогового окна после закрытия
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    // Инициализация GTK
    gtk_init(&argc, &argv);

    // Создание нового окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Пример приложения");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Обработка события закрытия окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Создание кнопки
    button = gtk_button_new_with_label("Нажми меня");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), window); // Передаем окно как данные

    // Добавление кнопки в окно
    gtk_container_add(GTK_CONTAINER(window), button);

    // Показать все элементы в окне
    gtk_widget_show_all(window);

    // Запуск основного цикла GTK
    gtk_main();

    return 0;
}