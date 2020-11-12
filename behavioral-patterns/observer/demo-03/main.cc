#include <unistd.h>
#include <memory>

#include "performance_publisher.h"
#include "mcall_subscriber.h"

using namespace dp;
typedef std::shared_ptr<PerformancePublisher> PerPubPtr;
typedef std::shared_ptr<McallSubscriber> McallSubPtr;

void EventLoop(PerPubPtr, McallSubPtr);

int main(void) {
  PerPubPtr per_ptr = std::make_shared<PerformancePublisher>();
  McallSubPtr mcall_ptr = std::make_shared<McallSubscriber>(per_ptr);

  EventLoop(per_ptr, mcall_ptr);

  return 0;
}

void EventLoop(PerPubPtr per_ptr, McallSubPtr mcall_ptr) {
  unsigned int counter = 0;
  for(;;) {
    if (counter % 10 == 0) {
      per_ptr->OnPublish();
    }

    mcall_ptr->ShowAppData();

    counter++;
    sleep(1);
  }
}
