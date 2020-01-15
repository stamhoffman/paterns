#ifndef PATERNS_H
#define PATERNS_H

class Singleton;

class SingletonDestroyer {
 private:
  Singleton *p_instance;

 public:
  ~SingletonDestroyer();
  void initialize(Singleton *p);
};

class Singleton {
 private:
  static Singleton *p_instance;
  static SingletonDestroyer destroyer;

 protected:
  Singleton() {}
  Singleton(const Singleton &);
  Singleton &operator=(Singleton &);
  ~Singleton() {}
  friend class SingletonDestroyer;

 public:
  static Singleton &Instance();
};

class Command {};

#endif  // PATERNS_H
