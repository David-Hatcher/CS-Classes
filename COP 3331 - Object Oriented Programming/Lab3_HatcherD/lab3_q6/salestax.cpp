#include "salestax.h"
const double taxval = 0.06;

namespace taxes{
    double getTax(double total){
        double tax = total*(taxval);
        int tax_two_dec = (int)round(tax*100);
        return ((double)tax_two_dec / 100.0);
    }
    double getTotalPlusTax(double total){
        double tax = getTax(total);
        double total_with_tax = total + tax;
        return total_with_tax;
    }
}