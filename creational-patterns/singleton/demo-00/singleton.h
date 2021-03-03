#ifndef SINGLETON_H_
#define SINGLETON_H_

// Scott Meyer's Singleton

class Singleton {
 public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton& GetInstance() {
    static Singleton s;
    return s;
  }

 private:
  Singleton() = default;
  ~Singleton() = default;
};

#endif  // SINGLETON_H_
