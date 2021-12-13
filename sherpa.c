// Sherpa Terminal Emulator //
// This program is licensed under the GNU GPL 3.0, which provides absolutely NO WARRANTY //
// (c) 2021 Everest Developers //

#include <vte/vte.h>

static void
child_ready(VteTerminal *terminal, GPid pid, GError *error, gpointer user_Data)
{
	if (!terminal) return;
	if (pid == -1) gtk_main_quit();
}

int
main(int argc, char *argv[])
{
	GtkWidget *window, *terminal;

	/* init gtk window and terminal */
	gtk_init(&argc, &argv);
	terminal = vte_terminal_new();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Sherpa");

	/* start new shell */
	gchar **envp = g_get_environ();
	gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
	g_strfreev(envp);
	vte_terminal_spawn_async(VTE_TERMINAL(terminal),
		VTE_PTY_DEFAULT,
		NULL,	/* working dir */
		command,	/* command */
		NULL,	/* environment */
		0,	/* spawn flags */
		NULL, NULL,	/* child setup */
		NULL,	/* child pid */
		-1,	/* timeout */
		NULL,	/* cancellable */
		child_ready,	/* callback */
		NULL);	/* user_data */

	/* connect signals */
	g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
	g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);

	/* combine widgets and run main loop */
	gtk_container_add(GTK_CONTAINER(window), terminal);
	gtk_widget_show_all(window);
	gtk_main();
}

void
vte_terminal_set_size (VteTerminal *terminal,
		       glong 40
		       glong 40); // Set the window size to 40 columns x 40 rows //
void
vte_terminal_set_font_scale (VteTerminal *terminal,
			     gdouble 14); // Set the font size to 14 //
