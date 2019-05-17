#include <gtk/gtk.h>

void on_menubar_add_clicked(GtkWidget *widget, gpointer data){
	GtkBuilder *builder;
	GtkWidget *addassist;

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder,"glade/sge.glade",NULL);
	
	addassist = GTK_WIDGET(gtk_builder_get_object(builder,"addassist"));

	g_signal_connect(G_OBJECT(addassist),"clicked",G_CALLBACK(addassist),data);

	g_object_unref(builder);

	gtk_widget_show_all(addassist);
}

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *mainw;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/sge.glade", NULL);

    mainw = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(mainw);
    gtk_main();

    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}
