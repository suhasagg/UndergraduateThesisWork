//入力 K_xy基底の多項式:polynomial_xy(基底(多項式)の数:polynomial_num), 
//     定義方程式:defined_polynomial
//出力 polynomial_xyをK_x基底にしたものをpolynomial_xとして出力

void Kxy2Kx(Fp_polynomial **polynomial_xy, int polynomial_num, Fp_polynomial **polynomial_x, Fp_polynomial *defined_polynomial){
  int i, j, k;
  Fp_polynomial **work_A = new_matrix(polynomial_num*a, 2*a-1);
 
  //work_A[polynomial_num][a]にpolynomial_xyの値を代入
  //さらにそれに、y^1, y^2, ... , y^(a-1) したものも代入 
  for(i=0 ; i<polynomial_num ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	work_A[a*i+k][j+k] = polynomial_xy[i][j];
      }
    }
  }

  //確認
  /*
  for(i=0 ; i<polynomial_num*a ; i++){
    for(j=0 ; j<2*a-1 ; j++){
      //if(work_A[i][j]!=zero_polynomial)
      cout << i << j << "  " << work_A[i][j] << "\n";
    }
  }
  cout << "\n";
  */
  
  //上で代入されたwork_aに定義方程式を代入してyの次数をa未満にする
  for(i=0 ; i<polynomial_num*a ; i++){
    for(j=2*a-2 ; j>=a ; j--){
      if(work_A[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //定義方程式を代入
	  work_A[i][j-k] = work_A[i][j-k] - work_A[i][j]*defined_polynomial[a-k];
	}
	work_A[i][j].assign_zero(MODULO);
      }
    }
  }
  
  //確認
  /*
  for(i=0 ; i<polynomial_num*a ; i++){
    for(j=0 ; j<2*a-1 ; j++){
      //if(work_A[i][j]!=zero_polynomial)
      cout << i << j << "  " << work_A[i][j] << "  \n";
    }
  }
  */

  for(i=0 ; i<polynomial_num*a ; i++){
    for(j=0 ; j<a ; j++){
      polynomial_x[i][j] = work_A[i][j];
    }
  }

  //確認
  //for(i=0 ; i<polynomial_num*a*a ; i++) cout << i << "  " << polynomial_x[i] << "\n";
}
