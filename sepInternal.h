#ifndef INTERNAL_H
#define INTERNAL_H 1
#ifdef __cplusplus

extern "C" {
#endif
void initFromArgs(const int argc, const char **argv);
void initFromName(const char *name);
int getSepArgC();
char **getSepArgV();
#ifdef __cplusplus
}
#endif
#endif
