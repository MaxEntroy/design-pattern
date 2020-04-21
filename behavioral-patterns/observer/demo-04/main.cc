#include <unistd.h>

#include "performance_publisher.h"
#include "mcall_subscriber.h"

using namespace dp;

typedef std::shared_ptr<PerformancePublisher> PerPubPtr;
typedef std::shared_ptr<McallSubscriber> McallSubPtr;

void EventLoop();

int main(void) {

  EventLoop();

  return 0;
}

void EventLoop() {
  PerPubPtr per_ptr = std::make_shared<PerformancePublisher>();
  McallSubPtr mcall_ptr = std::make_shared<McallSubscriber>(per_ptr);
  per_ptr->Attach(mcall_ptr);

  for(unsigned int counter = 0; counter < 60; counter++) {
    if (counter % 5 == 0) {
      per_ptr->OnPublish();
      mcall_ptr->Update();
    }
    mcall_ptr->ShowAppData();

    sleep(1);
  }
}
