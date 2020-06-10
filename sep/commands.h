#ifndef COMMANDS_H
#define COMMANDS_H 1
#include <memory>
#include <string.h>

/*!
  Class for accessing IO from fortran. Singleton class
  */
class sepCommands
{
private:
  /*!
    Initialize default fortran object
    */
  sepCommands() { ; }

  sepCommands(const sepCommands &rs);
  sepCommands &operator=(const sepCommands &rs);
  static std::shared_ptr<sepCommands> instance;
  int sepArgC;
  bool noArgs = true;
  char **sepArgV;

public:
  void resetIt(const int argc, const char **argv);
  void setHaveArgs() { noArgs = false; }
  void setup(const int argc, const char **argv);
  void setup(const char *name);
  ~sepCommands() { ; }
  char **getArgV() { return sepArgV; }
  int getArgC() { return sepArgC; }
  bool haveNoArgs()
  {
    return noArgs;
  }
  void getArg(const int iarg, char *buf)
  {
    if (iarg >= sepArgC)
      strcpy(buf, "");
    else
      strcpy(buf, sepArgV[iarg]);
  }
  static std::shared_ptr<sepCommands> &getInstance()
  {
    if (!instance)
    {
      instance.reset(new sepCommands());
    }

    return instance;
  }
};

#endif
