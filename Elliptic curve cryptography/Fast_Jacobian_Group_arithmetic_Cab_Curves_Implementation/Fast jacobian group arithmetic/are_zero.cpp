//polynomial_xを入力して
//polynomial_x==0なら1, polynomial_x!=0なら0を返す


int are_zero(Fp_polynomial *polynomial_x){
  int i;
  for(i=0 ; i<a ; i++){
    if(!(polynomial_x[i].is_zero()))  break;
  }
  if(i!=a) return 0;
  if(i==a) return 1;
}
