#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "strategy.h"

class Context {
 public:
  Context() {}
  explicit Context(Strategy* p) : strategy_(p) {}
  ~Context() {delete strategy_;}

 public:
  void ContextInterface();

 private:
  Strategy* strategy_;
};

#endif
