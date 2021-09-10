

void print_polynomial_x(Fp_polynomial *polynomial_x){
  int i, j;
  
  if(are_zero(polynomial_x)==1) cout << "0_polynomial\n" ;
  else{
    for(i=a-1 ; i>=0 ; i--){
      if(!(polynomial_x[i].is_zero())){
	cout << "(" << polynomial_x[i] << ")*y^" << i << "\n" ;
      }
    }
  }
  cout << "\n" ;
}
