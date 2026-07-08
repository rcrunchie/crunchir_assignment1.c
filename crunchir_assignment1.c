#include <math.h>
#include <stdbool.h>
#include <stdio.h>

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

//a = sqrt(R^2 - (ha)^2)
double calculate_a(double R, double ha) {
    return sqrt(pow(R, 2) - pow(ha, 2)); 
}

//b = sqrt(R^2 - (hb)^2)
double calculate_b(double R, double hb) {
    return sqrt(pow(R, 2) - pow(hb, 2));
}

//h = ha - hb
double calculate_h(double ha, double hb) {
    return ha - hb;
}

//tsa = (pi)a^2
double calculate_tsa(double a) {
    return (pi) * pow(a, 2);
}

//bsa = (pi)b^2
double calculate_bsa(double b) {
    return (pi) * pow(b, 2);
}

//lsa = 2(pi)R*h
double calculate_lsa(double R, double h) {
    return 2 * pi * R * h; 
}

//total_sa = tsa + bsa + lsa
double calculate_total_sa(double a, double b, double R, double h) {
    return calculate_tsa(a) + calculate_bsa(b) + calculate_lsa(R, h);
}

//v = (1/6)(pi)(h)(3a^2 + 3b^2 + h^2)
double calculate_v(double a, double b, double h) {
    return 0.2 * pi * h * ((3 * pow(a, 2)) + (3 * pow(b, 2)) + pow(h, 2));
}

//R, ha, and hb but must positive real values
bool check_parameters(double R, double ha, double hb) {
    int counter = 0;

    if(R >=0)
        counter++;
    else if(ha >= 0)
        counter++;
    else if(hb >= 0)
        counter++;

    if(counter<3)
        return false;
    else if(counter == 3)
        return true;
    else   
        return false;
}

//ha and hb must never be bigger than R
bool check_hs(double R, double ha, double hb) {
    int counter = 0;

    if(R > ha)
        counter++;
    else if(R > hb)
        counter++;
    
    if(counter<2)
        return false;
    else if(counter == 2)
        return true;
    else   
        return false;

}

//ha must be bigger than or equal to hb
bool check_ha(double ha, double hb) {
    return ha>=hb;
}

//integrate all parameter checks
bool validate_values(double R, double ha, double hb) {
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

bool check_seg_num(int n)
{
    if(n>=2 && n<=10)
        return true;
    else
        return false;
}

//average all total surface areas
double average_sa(double total_sa[]) {
    int array_len = *(&total_sa + 1) - total_sa;
    int total = 0;

    for(int i = 0; i < array_len; i++)
    {
        total += total_sa[i];
    }

    return total/array_len;
}

//average all volumes
double average_v(double volumes[]) {
    int array_len = *(&volumes + 1) - volumes;
    int total = 0;

    for(int i = 0; i < array_len; i++)
    {
        total += volumes[i];
    }

    return total/array_len;
}

void main() {
    bool seg_check = false;
    while (!seg_check)
    {
        printf("How many spherical segments you want to evaluate [2-10]?");
        scanf("%d", &n);
        seg_check = check_seg_num(n);
    }

    //create total sa and v arrays
    double total_sa[n];
    double volumes[n];
    
    for(int i = 0; i < n; i++)
    {
        printf("Obtaining data for spherical segment number %d", i);
    
        //ask user "What is the radius of the sphere(R)?"
        printf("What is the radius of the sphere(R)?");
        scanf("%lf\n", &R);

        //ask user "What is the height of the top area of the spherical segment(ha)?"
        printf("What is the height of the top area of the spherical segment(ha)?");
        scanf("%lf\n", &ha);

        //ask user "What is the height of the bottom area of the spherical segment(hb)?"
        printf("What is the height of the bottom area of the spherical segment(hb)?");
        scanf("%lf\n", &hb);

        //print "Entered data: R = ha = hb = ."
        printf("Entered data: R = %lf\n ha = %lf\n hb = %lf\n.", R, ha, hb);

        bool check_param = false;
        while(!check_param)
        {
            check_param = validate_values(R, ha, hb);
            //print "Invalid Input."
            printf("Invalid Input.");
        }

        double a = calculate_a(R, ha);
        double b = calculate_b(R, hb);
        double h = calculate_h(ha, hb);
        double total_sa = calculate_total_sa(a, b, R, h);
        double v = calculate_v(a, b, h);
        
        //print "Total Surface Area = Volume = ."
        printf("Total Surface Area = %lf\n Volume = %lf\n.", total_sa, v);
    }

    double total_sa_avg = average_sa(total_sa);
    double v_avg = average_v(volumes);

    //print "Total average results:"
    printf("Total average results:");
    //print "Average Surface Area = Average Volume = ."
    printf("Average Surface Area = %lf\n Average Volume = %lf\n.", total_sa_avg, v_avg);
}