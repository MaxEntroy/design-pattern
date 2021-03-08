#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <pthread.h>

// Chenshuo's Singleton
class Singleton {
 public:
  static Singleton& GetInstance() {
    pthread_once(&once_flag_, &Singleton::Init);
    return *s_;
  }

 private:
  Singleton() {}
  ~Singleton() {}

  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);

  static void Init() { s_ = new Singleton(); }

  static pthread_once_t once_flag_;
  static Singleton* s_;
};

pthread_once_t Singleton::once_flag_ = PTHREAD_ONCE_INIT;

Singleton* Singleton::s_ = NULL;

#endif  // SINGLETON_H_
