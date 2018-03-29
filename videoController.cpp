#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include <gtk/gtk.h>

using namespace std;


void setStatus(string status)
{
	ofstream file;
	file.open("status.txt");
	file << status;
	file.close();
}


static void pauseVideo (GtkWidget *widget, gpointer data)
{
	setStatus("pause");
}

static void resumeVideo (GtkWidget *widget, gpointer data)
{
	setStatus("resume");
}

static void quitVideo (GtkWidget *widget, gpointer data)
{
	setStatus("quit");
	exit(EXIT_SUCCESS);
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  //create a new window, and set its title
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Video Tools");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

 	//Here we construct the container that is going pack our buttons
  grid = gtk_grid_new ();

  //Pack the container in the window
  gtk_container_add (GTK_CONTAINER (window), grid);

  button = gtk_button_new_with_label ("Pause video");
  g_signal_connect (button, "clicked", G_CALLBACK (pauseVideo), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label ("Resume video");
  g_signal_connect (button, "clicked", G_CALLBACK (resumeVideo), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);


  button = gtk_button_new_with_label ("Quit video");
  g_signal_connect (button, "clicked", G_CALLBACK (quitVideo), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 0, 1, 1);


  gtk_widget_show_all (window);

}


int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;
	
	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	
	return status;
	
}

