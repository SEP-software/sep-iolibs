#ifndef COMMANDS_H
#define COMMANDS_H 1
#include <memory>
#include <string.h>

/*!
  Class for accessing IO from fortran. Singleton class
  */
class sepCommands {
private:
  /*!
    Initialize default fortran object
    */
  sepCommands() { ; }

  sepCommands(const sepCommands &rs);
  sepCommands &operator=(const sepCommands &rs);
  static std::shared_ptr<sepCommands> instance;
  int sepArgC;
  char **sepArgV;

public:
  void reset(const int argc, const char **argv);
  void setup(const int argc, const char **argv);
  void setup(const char *name);
  ~sepCommands() { ; }
  char **getArgV() { return sepArgV; }
  int getArgC() { return sepArgC; }
  static std::shared_ptr<sepCommands> &getInstance() {
    if (!instance) {
      instance.reset(new sepCommands());
    }

    return instance;
  }
};

#endif
