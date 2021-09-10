//polynomial_x‚ð“ü—Í‚µ‚Ä
//polynomial_x==0‚È‚ç1, polynomial_x!=0‚È‚ç0‚ð•Ô‚·


int are_zero(Fp_polynomial *polynomial_x){
  int i;
  for(i=0 ; i<a ; i++){
    if(!(polynomial_x[i].is_zero()))  break;
  }
  if(i!=a) return 0;
  if(i==a) return 1;
}
