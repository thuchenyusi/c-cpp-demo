#define _GNU_SOURCE
// https://learn.microsoft.com/en-us/azure-sphere/app-development/watchdog-timer
#include <signal.h>
#include <stdio.h>
#include <time.h>

const struct itimerspec watchdogInterval = {{2, 0}, {2, 0}};

timer_t watchdogTimer;

void ThreadHandle(__sigval_t sig) {
  printf("%s", "ThreadHandle!\n");
  return;
}

void SetupWatchdog(void) {
  struct sigevent alarmEvent = {};

  // alarmEvent.sigev_notify = SIGEV_SIGNAL;
  alarmEvent.sigev_notify = SIGEV_THREAD;
  alarmEvent.sigev_notify_function = &ThreadHandle;

  alarmEvent.sigev_signo = SIGALRM;
  alarmEvent.sigev_value.sival_ptr = &watchdogTimer;

  int result = timer_create(CLOCK_MONOTONIC, &alarmEvent, &watchdogTimer);
  result = timer_settime(watchdogTimer, 0, &watchdogInterval, NULL);
}

// Must be called periodically
void ExtendWatchdogExpiry(void) {
  // check that application is operating normally
  // if so, reset the watchdog
  timer_settime(watchdogTimer, 0, &watchdogInterval, NULL);
}

int main() {
  size_t times = 5000;
  SetupWatchdog();
  for (size_t i = 0; i < times; i++) {
    printf("i: %zu\n", i);
    ExtendWatchdogExpiry();
    sleep(1);
  }
  for (;;)
    ;
  return 0;
}
