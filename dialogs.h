#ifndef DIALOGS_H
#define DIALOGS_H

#include <gtk/gtk.h>
#include <string>

using namespace std;

// Метод для отображения сообщения.
void showDialog(GtkWidget *widget, const string& message);

#endif // DIALOGS_H
