#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void sigma(int s)
{
  if (s == SIGINT)
  {
      char buf[128];
      sprintf(buf, "Sigma!!!!!!!\n");
      write(1, buf, strlen(buf));
  }
}

int
main ()
{
  struct sigaction sa;
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  sigprocmask(SIG_BLOCK, &mask, NULL);

  sigfillset(&sa.sa_mask);
  sa.sa_handler = sigma;
  sigaction(SIGINT, &sa, NULL);

  sigprocmask(SIG_UNBLOCK, &mask, NULL);
  
  char c;

  char buf[128];
  int r;
  r = read (0, &c, sizeof (char));

  if (r >= 0)
  {
    sprintf(buf, "Correct Read\n");
  }
  else if (r == -1)
  {
    if (errno == EINTR)
    {
      sprintf(buf, "Signal interrupted read\n");
    }
    else sprintf(buf, "Read with error\n");
  }

  write(1, &buf, strlen(buf));
}
