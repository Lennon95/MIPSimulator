#include <gtk/gtk.h>
#include <string.h>
#include "gui.h"

static GtkTextBuffer* regBuff;
static GtkTextBuffer* memBuff;
static GtkTextBuffer* _stdout;

static void updateRegBuff (const char* text, gint len)
{
	gtk_text_buffer_set_text(regBuff, text, len);
}

static void updateMemBuff (const char* text, gint len)
{
	gtk_text_buffer_set_text(memBuff, text, len);
}

static void updateStdout (const char* text, gint len)
{
	gtk_text_buffer_set_text(_stdout, text, len);
}

static void open_file (GtkWidget *widget, gpointer data)
{
	GtkWidget *dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
	gint res;

	dialog = gtk_file_chooser_dialog_new ("Abrir arquivo",
                                      NULL,
                                      action,
                                      "_Cancelar",
                                      GTK_RESPONSE_CANCEL,
                                      "_Abrir",
                                      GTK_RESPONSE_ACCEPT,
                                      NULL);

	res = gtk_dialog_run (GTK_DIALOG (dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
    		char *filename;
    		GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
    		filename = gtk_file_chooser_get_filename (chooser);
		updateStdout(filename, strlen(filename));
    		// open_file (filename);
		g_free (filename);
	}
	gtk_widget_destroy (dialog);
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
	g_signal_connect (button, "activate", G_CALLBACK (open_file), NULL);

	button = gtk_builder_get_object (builder, "button-quit");
	g_signal_connect_swapped (button, "activate", G_CALLBACK (g_application_quit), app);

	button = gtk_builder_get_object (builder, "quit");
	g_signal_connect (button, "clicked", G_CALLBACK (g_application_quit), NULL);


	regBuff = GTK_TEXT_BUFFER(gtk_builder_get_object (builder, "reg_buf"));
	memBuff = GTK_TEXT_BUFFER(gtk_builder_get_object (builder, "data_buf"));
	_stdout = GTK_TEXT_BUFFER(gtk_builder_get_object (builder, "stdout"));

	gtk_application_add_window (app, GTK_WINDOW(window));
	gtk_widget_show_all (GTK_WIDGET(window));	
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

