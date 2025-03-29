#include "dialogs.h"

void showDialog(GtkWidget *widget, const string& message) {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                     GTK_DIALOG_MODAL,
                                     GTK_MESSAGE_INFO,
                                     GTK_BUTTONS_OK,
                                     "%s", message.c_str()); // Используем c_str() для получения C-строки
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
