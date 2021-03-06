/* call specifications for commands.c */

#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include "pg_top.h"

struct cmd {
	int ch;
	int (*func)(struct pg_top_context *);
};

#define EXPLAIN 0
#define EXPLAIN_ANALYZE 1

#ifdef ENABLE_COLOR
int cmd_color(struct pg_top_context *);
#endif /* ENABLE_COLOR */
int cmd_cmdline(struct pg_top_context *);
int cmd_current_query(struct pg_top_context *);
int cmd_delay(struct pg_top_context *);
int cmd_displays(struct pg_top_context *);
int cmd_errors(struct pg_top_context *);
int cmd_explain(struct pg_top_context *);
int cmd_explain_analyze(struct pg_top_context *);
int cmd_help(struct pg_top_context *);
int cmd_idletog(struct pg_top_context *);
int cmd_indexes(struct pg_top_context *);
int cmd_io(struct pg_top_context *);
#ifdef ENABLE_KILL
int cmd_kill(struct pg_top_context *);
#endif /* ENABLE_KILL */
int cmd_locks(struct pg_top_context *);
int cmd_number(struct pg_top_context *);
int cmd_quit(struct pg_top_context *);
int cmd_order(struct pg_top_context *);
int cmd_order_cpu(struct pg_top_context *);
int cmd_order_mem(struct pg_top_context *);
int cmd_order_pid(struct pg_top_context *);
int cmd_order_time(struct pg_top_context *);
int cmd_redraw(struct pg_top_context *);
#ifdef ENABLE_KILL
int cmd_renice(struct pg_top_context *);
#endif /* ENABLE_KILL */
int cmd_statements(struct pg_top_context *);
int cmd_tables(struct pg_top_context *);
int cmd_toggle(struct pg_top_context *);
int cmd_update(struct pg_top_context *);
int cmd_user(struct pg_top_context *);

int execute_command(struct pg_top_context *, char);

void show_help(struct statics *);
int scanint(char *str, int *intp);
int error_count();
void show_errors();
char *kill_procs(char *str);
char *renice_procs(char *str);
void show_current_query(char *, int);
void show_explain(char *, int, int);
void show_locks(char *, int);

#endif   /* _COMMANDS_H_ */
