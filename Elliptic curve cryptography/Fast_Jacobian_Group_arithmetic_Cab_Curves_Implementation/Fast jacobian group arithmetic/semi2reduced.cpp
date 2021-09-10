//入力 : **ideal, *defined_polynomial, **delta
//出力 : **reduced_ideal, &reduced_ideal_e
//ideal(semi-reduced)からreduced-idealを求める


void semi2reduced(Fp_polynomial **ideal, Fp_polynomial *defined_polynomial, Fp_polynomial **delta, Fp_polynomial **reduced_ideal, Fp_polynomial &reduced_ideal_e){
  int i, j;

  //Algorithm.5  逆イデアルを求める
  Fp_polynomial e(ZERO, MODULO), **matrix_W = new_matrix(a, a);
  get_inverse_ideal(ideal, delta, matrix_W, e, defined_polynomial);

  //確認
  cout << "e = " << e <<"\n" ;
  cout << "matrix_W = \n" ;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      cout << i << j << "     " << matrix_W[i][j] <<"\n" ;
    }
  }

  //確認 : Wが入力されたイデアル(ideal)の逆イデアルになっているかどうかの確認
  //イデアルidealとイデアルとのイデアル積を計算してそれをideal_prdctWとする
  Fp_polynomial **ideal_prdctW = new_matrix(a*a ,a);
  multiply_ideal(ideal, matrix_W, ideal_prdctW, defined_polynomial);
  
  cout << "kakunin of inverse_ideal W\n" ;
  for(i=0 ; i<a*a ; i++){
    print_polynomial_x(ideal_prdctW[i]);
    cout << endl ;
  }

  Fp_polynomial **ideal_prdctWHNF = new_matrix(a, a);
  HNF(ideal_prdctW, ideal_prdctWHNF, a*a);
  //確認
  cout << "ideal_prdctWHNF = \n" ;
  for(i=0 ; i<a ; i++){
    print_polynomial_x(ideal_prdctWHNF[i]);
  }
  

  //行列matrix_Wから最小元fを求める
  Fp_polynomial *f = new_vector(a);
  get_minimum_element(matrix_W, f);
  //確認
  cout << "f = \n" ;
  print_polynomial_x(f);

  //最小元fの基底をK_xyからK_xに変換してそれを,f_xに入れる
  Fp_polynomial **f_x = new_matrix(a, a);
  Fp_polynomial **fff = new_matrix(1, a);   //(*f)を(**fff)に直す
  for(i=0 ; i<a ; i++)  fff[0][i] = f[i];   //Kxy2Kxの最初の引数は行列しか受け付けないから
  Kxy2Kx(fff, 1, f_x, defined_polynomial);
  //確認
  cout << "f_x = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(f_x[i]);

  //イデアルidealとイデアルf_xとの積を計算してそれをideal_f_xとする
  Fp_polynomial **ideal_f_x = new_matrix(a*a ,a);
  multiply_ideal(ideal, f_x, ideal_f_x, defined_polynomial);
  //確認
  cout << "ideal_f_x = \n" ;
  for(i=0 ; i<a*a ; i++)  print_polynomial_x(ideal_f_x[i]);


  /*****************************************************************/
  //さらにそれ(ideal_f_x)のすべての要素を e で割ったものを新たにideal_f_xとする
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<a ; j++){
      ideal_f_x[i][j] = ideal_f_x[i][j] / e ;
    }
  } 
  /******************************************************************/
  //上で求めたideal_f_x[a*a][a]をHNF
  Fp_polynomial **ideal_f_xHNF = new_matrix(a, a);
  HNF(ideal_f_x, ideal_f_xHNF, a*a);
  //確認
  cout << "ideal_f_xHNF = (in main at the end of HNF )" << "\n" ;
  for(i=0 ; i<a ; i++){
    cout << "ideal_f_xHNF[" << i << "] = \n" ;
    print_polynomial_x(ideal_f_xHNF[i]);
  }

  
  //上で求めたideal_f_xHNF[a][a] = reduced_ideal とする
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      reduced_ideal[i][j] = ideal_f_xHNF[i][j] ;
    }
  }
  //RE_ideal_e = e とする
  reduced_ideal_e = e;

  //上で求めたideal_f_xHNF[a][a]のすべての要素を e で割る
  /*
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      reduced_ideal[i][j] = ideal_f_xHNF[i][j]/e ;
    }
  }
  //確認
  cout << "reduced_ideal = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(reduced_ideal[i]);
  */

}
