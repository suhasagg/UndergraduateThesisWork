//polynomial_x����͂���
//polynomial_x==0�Ȃ�1, polynomial_x!=0�Ȃ�0��Ԃ�


int are_zero(Fp_polynomial *polynomial_x){
  int i;
  for(i=0 ; i<a ; i++){
    if(!(polynomial_x[i].is_zero()))  break;
  }
  if(i!=a) return 0;
  if(i==a) return 1;
}
