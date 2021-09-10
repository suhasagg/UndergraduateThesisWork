//“ü—Ípolynomial_g[a]‚©‚çpolynomial_g[a]‚ÌŸ”(C_ab’l)‚Æ‚»‚ÌˆÊ’u‚ğ•Ô‚·


void degree_Cab(Fp_polynomial *polynomial_g, /*big*/int &deg, int &leading_position){
  int i;
  int work_deg;
  //bigint work_deg;
  deg=0;
  
  //cout << "ZERO?   " << are_zero(polynomial_g) << "\n" ;
  //for(i=0 ; i<a ; i++)  cout << i << "    " << polynomial_g[i] << "\n" ;

  if(are_zero(polynomial_g)==1){
    leading_position=0;
    //cout << leading_position << "  in degree_Cab leading_position(if)\n" ;
  }  
  else{
    for(i=0 ; i<a ; i++){
      if(!(polynomial_g[i].is_zero())){
	work_deg = (polynomial_g[i].degree())*a + b*i;
	if(work_deg>=deg){
	  deg = work_deg;
	  leading_position = i;
	  //cout << leading_position << "  in degree_Cab leading_position(else)\n" ;
	}
      }
    }
  }
}
