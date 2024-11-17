#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#define REGION_SIZE		4096

int *p;

void sigtreat(int s)
{
  char buff[256];
  sprintf (buff, "Error: seg fault\n");
  write (1, buff, strlen (buff));

  exit (0);
}

int
main (int argc, char *argv[])
{
  struct sigaction sa;
  sigset_t mask;
  sigfillset(&mask);
  sa.sa_handler = sigtreat;
  sa.sa_mask = mask;

  sigaction(SIGSEGV, &sa, NULL);

  char buff[256];

  sprintf (buff, "Addresses:\n");
  write (1, buff, strlen (buff));
  sprintf (buff, "\tp: %p\n", &p);
  write (1, buff, strlen (buff));

  *p = 5;

  sprintf (buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
  write (1, buff, strlen (buff));

  exit (0);

}
