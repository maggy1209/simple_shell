#include "shell.h"

int main()
{
  char cmd[MAX_CMD_LEN];
  char *args[MAX_CMD_LEN / 2];
  int i, status;

  while (1) {
    printf("shell>");
    fgets(cmd, MAX_CMD_LEN, stdin);
   // Check for end of file
    if (cmd[0] == '\n') {
      break;
    }
   // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid == 0) {
      execvp(cmd, NULL);
      printf("Error: Could not execute command '%s'\n", cmd);
      exit(1);
    } else {
      waitpid(pid, &status, 0);
    }
  }
  return 0;
}
