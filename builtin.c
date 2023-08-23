#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  char *command;
  int pid;

  // Display the prompt
  printf("enter command$ ");

  // Read the command from the user
  command = fgets(NULL, 0, stdin);

  // Check if the user entered an empty command
  if (command == NULL) {
    return 0;
  }

  // Strip the newline character from the end of the command
  command[strcspn(command, "\n")] = '\0';

  // Fork a child process to execute the command
  pid = fork();

  if (pid == 0) {
    // In the child process, execute the command
    execvp(command, NULL);

    // If the execvp() function fails, print an error message
    perror("execvp");
    exit(1);
  }

  // In the parent process, wait for the child process to exit
  waitpid(pid, NULL, 0);

  // Display the prompt again
  printf("enter command$ ");

  return 0;
}
