

void input_defined_polynomial(Fp_polynomial *defined_polynomial){
  int coeff, deg_x, deg_y;
  Fp_polynomial work;
  //’è‹`•û’öŽ® defined_polynomial ‚ð“ü—Í
  cout << "Input defined polynomial\n" ;
  for(int i=0 ; ; i++){
    cin >> coeff >> deg_x >> deg_y ;
    if(coeff==0) break;
    if(deg_y>a){
      cout << "Input deg_y>a (RETRY)\n" ;
      exit(0);
    }
    work.assign_zero(MODULO);
    work.set_coefficient(coeff, deg_x);
    defined_polynomial[deg_y] = defined_polynomial[deg_y] + work;
  }
  //Šm”F
  /*
  cout << "defined_polynomial = \n" ;
  cout << "(" << defined_polynomial[a] << ")*y^" << a << "\n" ;
  print_polynomial_x(defined_polynomial);
  */
}
