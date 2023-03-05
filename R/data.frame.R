
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' A benchmarking demo which creates a data.frame (and populates it) totally 
#' within C
#' 
#' @param n number of rows to generate. Default: 8
#' 
#' @return a data.frame created within C
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
deft_benchmark <- function(n = 8) {
  .Call(deft_benchmark_, n)
}
