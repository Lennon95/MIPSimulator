#include <gtk/gtk.h>

static void print_hello (GtkWidget *widget, gpointer data)
{
	g_print ("Hello World\n");
}

static void activate (GtkApplication *app, gpointer user_data)
{
	GtkBuilder *builder;
	GObject *window;
	GObject *button;
	GError *error = NULL;

	/* Construct a GtkBuilder instance and load our UI description */
	builder = gtk_builder_new_from_file ("glade.ui");
	/*if (gtk_builder_add_from_file (builder, "glade.ui", &error) == 0) {
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}*/

	/* Connect signal handlers to the constructed widgets. */
	window = gtk_builder_get_object (builder, "window");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	button = gtk_builder_get_object (builder, "button-open");
	g_signal_connect (button, "activate", G_CALLBACK (print_hello), NULL);

	button = gtk_builder_get_object (builder, "button-quit");
	g_signal_connect_swapped (button, "activate", G_CALLBACK (g_application_quit), app);

	button = gtk_builder_get_object (builder, "quit");
	g_signal_connect (button, "clicked", G_CALLBACK (g_application_quit), NULL);

	gtk_application_add_window (app, GTK_WINDOW(window));
	gtk_widget_show_all (GTK_WIDGET(window));
	//gtk_main ();
}

int main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}

