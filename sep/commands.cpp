#include "commands.h"
#include "sep_pars_external.h"

std::shared_ptr<sepCommands> sepCommands::instance = nullptr;
void sepCommands::reset(const int argc, const char **argv) {
  for (int i = 0; i < argc; i++) 
    free(sepArgV[i]);
  free(sepArgV);
   setup(argc,argv);
}
void sepCommands::setup(const int argc, const char **argv) {
  sepArgV = (char **)malloc(argc * sizeof(char *));
  sepArgC = argc;
  for (int i = 0; i < argc; i++) {
    sepArgV[i] = (char *)malloc(sizeof(char) * (strlen(argv[i]) + 1));
    strcpy(sepArgV[i], argv[i]);
  }
}
void sepCommands::setup(const char *name) {
  sepArgV = (char **)malloc(1 * sizeof(char *));
  sepArgC = 1;
  sepArgV[0] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(sepArgV[0], name);
}
void initFromArgs(const int argc, const char **argv) {
  sepCommands::getInstance()->setup(argc, argv);
}
void initFromName(const char *name) { sepCommands::getInstance()->setup(name); }
int getSepArgC() { return sepCommands::getInstance()->getArgC(); }
char **getSepArgV() { return sepCommands::getInstance()->getArgV(); }
void resetSepArgCV(const int argc, const char **argv){

  sepCommands::getInstance()->reset(argc, argv);

}
