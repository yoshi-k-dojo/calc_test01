#include <gtk/gtk.h>


static void exit_button_clicked(GtkWidget *button, gpointer user_data)
{
    gtk_main_quit();
}

static void num1_button_clicked(GtkWidget *button, gpointer user_data)
{
    GtkWidget *display_label = (GtkWidget *)user_data;
    long new_display_num;
    char new_display_str[20];

    new_display_num = atol(gtk_label_get_text(display_label)) * 10 + 1;
    sprintf(new_display_str, "%ld", new_display_num);
    gtk_label_set_text(display_label, new_display_str);
    printf("%ld\n", new_display_num);
}

static void c_button_clicked(GtkWidget *button, gpointer user_data)
{
    GtkWidget *display_label = (GtkWidget *)user_data;

    gtk_label_set_text(display_label, "0");
}

int main(int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *exit_button;
    GtkWidget *display_label;
    GtkWidget *num1_button;
    GtkWidget *c_button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "電卓");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    fixed  = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    exit_button = gtk_button_new_with_label("終了");
    gtk_widget_set_size_request(exit_button, 100, 20);
    gtk_fixed_put(GTK_FIXED(fixed), exit_button, 250, 360);
    g_signal_connect(G_OBJECT(exit_button), "clicked", G_CALLBACK(exit_button_clicked), NULL);

    display_label = gtk_label_new("0");
    gtk_fixed_put(GTK_FIXED(fixed), display_label, 10, 10);

    num1_button = gtk_button_new_with_label("1");
    gtk_widget_set_size_request(num1_button, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixed), num1_button, 40, 300);
    g_signal_connect(G_OBJECT(num1_button), "clicked", G_CALLBACK(num1_button_clicked), display_label);

    c_button = gtk_button_new_with_label("C");
    gtk_widget_set_size_request(c_button, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixed), c_button, 400, 100);
    g_signal_connect(G_OBJECT(c_button), "clicked", G_CALLBACK(c_button_clicked), display_label);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
