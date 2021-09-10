

void input_ideal(Fp_polynomial **ideal){
  int coeff, deg_x, deg_y;
  Fp_polynomial work;
  //ideal‚ÌŠî’ê(ideal) ‚ð“ü—Í
  for(int i=0 ; i<a ; i++){
    cout << "Input basis of ideal[" << i << "]" << "\n" ;
    for(int j=0 ; ; j++){
      cin >> coeff >> deg_x >> deg_y ;
      if(coeff==0) break;
      if(deg_y>=a){
	cout << "Input deg_y>a (RETRY)\n" ;
	exit(0);
      }
      work.assign_zero(MODULO);
      work.set_coefficient(coeff, deg_x);
      ideal[i][deg_y] = ideal[i][deg_y] + work;
      //ideal_1_xy[i][deg_y].set_coefficient(coeff, deg_x);
    }
    //Šm”F
    //cout << "ideal[" << i << "] = \n" ; 
    //print_polynomial_x(ideal[i]);
  }
}
