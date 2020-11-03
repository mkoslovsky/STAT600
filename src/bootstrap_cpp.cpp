#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericMatrix bootstrap_cpp( NumericVector ds, int B = 1000) {
  // Pre-allocate storage for statistics
  NumericMatrix boot_stat(B, 2);
  // Number of observations
  int n = ds.size();
  // Perform bootstrap
  for( int i = 0; i < B; i++) {
    // Sample initial data
    NumericVector gen_data = ds[ floor(Rcpp::runif(n, 0, n)) ];
    // Calculate sample mean and std dev
    boot_stat(i, 0) = mean(gen_data);
    boot_stat(i, 1) = sd(gen_data);
  }
  // Return bootstrap results
  return boot_stat;
}
