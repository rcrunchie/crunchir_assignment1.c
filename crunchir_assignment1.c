#include <math.h>

//compile using gcc --std=gnu99 -o t try.c -lm

double pi = 3.13159265359;
double R, ha, hb, v;
int n;
double a, b, h;
/* Key
    R = radius of sphere
    ha = height of top area of spherical segment
    hb = height of bottom area of spherical segment
    n = valid sets of values evaluated 
    a = 
    b = 
    h = height difference
    tsa = top surface area
    bsa = bottom surface area
    lsa = lateral surface area
    total_sa = total surface area
    v = volume
*/

/* Parameters
    * Parameters R, ha, and hb must be positive real values.
    * Also, ha and hb must never be bigger than the value of parameter R, 
    and  ha should always be bigger than or equal to hb.
    * If any of these conditions is violated in a set, a message 
    indicating that the input is invalid must be printed, all these 
    parameters must be rejected, and new values must be requested from
    the user.
    * n must fall within range of 2-10
*/

/* Formulas
    a = sqrt(R^2 - (ha)^2)
    b = sqrt(R^2 - (hb)^2)
    h = ha - hb
    tsa = (pi)a^2
    bsa = (pi)b^2
    lsa = 2(pi)R*h
    total_sa = tsa + bsa + lsa
    v = (1/6)(pi)(h)(3a^2 + 3b^2 + h^2)
*/

int main() {

}

//a = sqrt(R^2 - (ha)^2)
double calculate_a(double R, double ha) {
    return 
}

//b = sqrt(R^2 - (hb)^2)
double calculate_b(double R, double hb) {
    
}

//h = ha - hb
double calculate_h(double ha, double hb) {
    
}

//tsa = (pi)a^2
double calculate_tsa(double a) {
    
}

//bsa = (pi)b^2
double calculate_bsa(double b) {
    
}

//lsa = 2(pi)R*h
double calculate_lsa(double R, double h) {
    
}

//total_sa = tsa + bsa + lsa
double calculate_total_sa(double a, double b, double R, double h) {
    return calculate_tsa(a) + calculate_bsa(b) + calculate_lsa(R, h);
}

//v = (1/6)(pi)(h)(3a^2 + 3b^2 + h^2)
double calculate_v(double a, double b, double h) {
    
}

//R, ha, and hb but must positive real values
bool check_parameters(double R, double ha, double hb) {

}

//ha and hb must never be bigger than R
bool check_hs(double R, double ha, double hb) {

}

//ha must be bigger than or equal to hb
bool check_ha(double ha, double hb) {

}

//integrate all parameter checks
bool validate_value(double R, double ha, double hb) {
    int counter = 0;

    if(check_parameters(R, ha, hb))
        counter++;
    else if(check_hs(R, ha, hb))
        counter++;
    else if(check_ha(ha, hb))
        counter++;

    if(counter<3)
        return false;
    else if(counter == 3)
        return true;
    else   
        return false;
    
}

//average all total surface areas
double average_sa(double total_sa[]) {
    int array_len = sizeof(total_sa)/sizeof(total_sa);

    for(int i = 0; i < array_len; i++)
    {

    }
}

//average all volumes
double average_v() {

}

