#include "singleton.h"
#include <iostream>

Singleton *Singleton::p_instance = 0;
SingletonDestroyer Singleton::destroyer;

SingletonDestroyer::~SingletonDestroyer() { delete p_instance; }

void SingletonDestroyer::initialize(Singleton *p_instance_) {
  p_instance = p_instance_;
}

Singleton &Singleton::Instance() {
  if (!p_instance) {
    p_instance = new Singleton();
    destroyer.initialize(p_instance);
    std::cout << "New" << std::endl;
  }
  std::cout << "Old" << std::endl;
  return *p_instance;
}
