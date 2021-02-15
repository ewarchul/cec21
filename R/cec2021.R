#' CEC 2021
#' 
#' @param i func_number
#' @param x input vector
#' @param suite:
#'        1 - basic
#'        2 - bias
#'        3 - bias-rot
#'        4 - bias-rot-shift
#'        5 - rot
#'        6 - shift
#'        7 - shift-rot
#'        8 - shift-bias
#' @export
#' @useDynLib cec21

cec2021 = function (i, x, suite) {
  if (missing(i)) stop("Missing argument; 'i' has to be provided !")

  if (missing(x)) stop("Missing argument; 'x' has to be provided !")
  if (is.numeric(i) && i >= 1 && i <= 10) {
    if (is.vector(x)) {
        row <- 1; col <- length(x)
    } else if (is.matrix(x)) {
         row <- nrow(x); col <- ncol(x)
      } else {
          stop("x should be a vector or a matrix")
        } # ELSE end

        if (!(col %in% c(10, 20))) {
            stop("Invalid argument: Only 10 and 20 dimensions/variables are allowed !")
        }
        extdatadir <- system.file("extdata", package = "cec21")
        f <- .C(
          "cec21",
          extdatadir = as.character(extdatadir),
          suitenum = as.integer(suite),
          i = as.integer(i),
          x = as.double(x),
          row = as.integer(row),
          col = as.integer(col),
          f = double(row),
          PACKAGE = "cec21"
        )$f
  } else stop("Invalid argument: 'i' should be an integer between 1 and 10 !")
  
  return(f)
}
