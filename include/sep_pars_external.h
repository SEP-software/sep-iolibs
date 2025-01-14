#ifndef SEP_PARS_EXTERNAL_H
#define SEP_PARS_EXTERNAL_H
#include <prototypes.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

    extern int auxpar(const char *, const char *, void *, const char *);
    extern int auxputch(const char *, const char *, const void *, const char *);
    extern int fetch(char *, char *, void *);
    extern int getch(const char *, const char *, void *);
    extern int getch_add_string(const char *);
    extern int hetch(char *, char *, void *);
    extern void initpar(const int, char **);
    extern int putch(char *, char *, void *);
    extern int auxputhead(const char *, const char *, ...);
    extern int puthead(char *, ...);
    extern int tetch(char *, char *, ...);
    extern int putlin(char *);
    void resetSepArgCV(const int argc, const char **argv);
    void initFromArgs(const int argc, const char **argv);
    void initFromName(const char *name);
    int getSepArgC();
    char **getSepArgV();
    int separg(const int, char *);
    int sep_prog(char *arg);
    bool doDoc();
    void haveArgs();
#ifdef __cplusplus
}
#endif

#endif
