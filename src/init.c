
#include <R.h>
#include <Rinternals.h>


extern SEXP deft_benchmark_();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Declarations for C code to make available to other packages
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern SEXP df_create();
extern SEXP df_add_row_core();
extern SEXP df_truncate_to_data_length();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C functions visible to R code in this packages
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static const R_CallMethodDef CEntries[] = {
  {"deft_benchmark_", (DL_FUNC) &deft_benchmark_, 1},
  {NULL , NULL, 0}
};


void R_init_deft(DllInfo *info) {
  R_registerRoutines(
    info,      // DllInfo
    NULL,      // .C
    CEntries,  // .Call
    NULL,      // Fortran
    NULL       // External
  );
  R_useDynamicSymbols(info, FALSE);
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Make the C code available to other packages
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  R_RegisterCCallable("deft", "df_create"                 , (DL_FUNC) &df_create                 );
  R_RegisterCCallable("deft", "df_add_row_core"           , (DL_FUNC) &df_add_row_core           );
  R_RegisterCCallable("deft", "df_truncate_to_data_length", (DL_FUNC) &df_truncate_to_data_length);
}



