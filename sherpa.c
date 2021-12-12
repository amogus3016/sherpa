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
