#include <unistd.h>

#include "performance_publisher.h"
#include "mcall_subscriber.h"

using namespace dp;

void EventLoop(PerformancePublisher*, McallSubscriber*);

int main(void) {
  PerformancePublisher* p_pub = new PerformancePublisher();
  McallSubscriber* p_sub = new McallSubscriber(p_pub);

  EventLoop(p_pub, p_sub);

  delete p_pub;
  delete p_sub;
  return 0;
}

void EventLoop(PerformancePublisher* p_pub,
               McallSubscriber* p_sub) {
  unsigned int counter = 0;
  for(;;) {
    if (counter % 10 == 0) {
      p_pub->OnPublish();
      p_sub->Update();
    }

    p_sub->ShowAppData();

    counter++;
    sleep(1);
  }
}
