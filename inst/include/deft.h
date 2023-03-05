#pragma once

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SEXP df_create(int ncol, char **names, int *types)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static inline SEXP df_create(int ncol, char **names, int *types) {
  static SEXP (*fun)(int,  char **, int *) = NULL;
  
  if (fun == NULL) {
    fun = (SEXP (*)(int, char **, int *)) R_GetCCallable("deft", "df_create");
  }
  
  return fun(ncol, names, types);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void df_add_row_core(SEXP df_, va_list args)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static inline void df_add_row_core(SEXP df_, va_list args) {
  static void (*fun)(SEXP, va_list) = NULL;
  
  if (fun == NULL) {
    fun = (void (*)(SEXP, va_list)) R_GetCCallable("deft", "df_add_row_core");
  }
  
  fun(df_, args);
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void df_truncate_to_data_length(SEXP df_) 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static inline void df_truncate_to_data_length(SEXP df_) {
  static void (*fun)(SEXP) = NULL;
  
  if (fun == NULL) {
    fun = (void (*)(SEXP)) R_GetCCallable("deft", "df_truncate_to_data_length");
  }
  
  fun(df_);
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This is the "user-friendly" version of "df_add_row()"
// which uses the standard C varargs syntax.
// It's just a simple wrapper around `df_add_row_core()` that takes
// care of the `...` and turns it into a `va_list`
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void df_add_row(SEXP df_, ...) {
  va_list args;
  va_start(args, df_);
  df_add_row_core(df_, args);
  va_end(args);
}

