#include <gtk/gtk.h>
//sudo apt-get install build-essential libgtk-3-dev libgtk2.0-dev
//g++ `pkg-config --cflags gtk+-2.0` -o main main.cpp `pkg-config --libs gtk+-2.0`

static gint delete_event_cb(GtkWidget* w, GdkEventAny* e, gpointer data);
static void button_click_cb(GtkWidget* w, gpointer data);
int
main(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* button;
    GtkWidget* label;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new();
    label = gtk_label_new("Hello, World!");
    gtk_container_add(GTK_CONTAINER(button), label);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_window_set_title(GTK_WINDOW(window), "Hello");
    gtk_container_set_border_width(GTK_CONTAINER(button), 10);
    gtk_signal_connect(GTK_OBJECT(window),
                       "delete_event",
                       GTK_SIGNAL_FUNC(delete_event_cb),
                       NULL);
    gtk_signal_connect(GTK_OBJECT(button),
                       "clicked",
                       GTK_SIGNAL_FUNC(button_click_cb),
                       label);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
static gint
delete_event_cb(GtkWidget* window, GdkEventAny* e, gpointer data)
{
    gtk_main_quit();
    return FALSE;
}
static void
button_click_cb(GtkWidget* w, gpointer data)
{
    GtkWidget* label;
    gchar* text;
    gchar* tmp;
    label = GTK_WIDGET(data);
    gtk_label_get(GTK_LABEL(label), &text);
    tmp = g_strdup(text);
    g_strreverse(tmp);
    gtk_label_set_text(GTK_LABEL(label), tmp);
g_debug("bar");
    g_free(tmp);
}
