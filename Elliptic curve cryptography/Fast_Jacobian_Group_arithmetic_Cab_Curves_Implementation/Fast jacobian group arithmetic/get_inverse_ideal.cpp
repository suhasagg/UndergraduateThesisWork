//get_inverse_ideal(Fp_polynomial *ideal_1_xHNF, Fp_polynomial *delta, 
//                  Fp_polynomial *W, Fp_polynomial &e, 
//                  Fp_polynomial *defined_polynomial)
//



void get_inverse_ideal(Fp_polynomial **ideal_1_xHNF, Fp_polynomial **delta, Fp_polynomial **matrix_W, Fp_polynomial &e, Fp_polynomial *defined_polynomial){
  
  int i, j, k, h;

  //行列deltaと行列ideal_1_xHNFから行列R求める
  //Fp_polynomial /*matrix_R[a*a][2*a-1],*/  matrix_RR[a*a][a], work_delta[a][a], work_gamma[a][a];
 
  Fp_polynomial **matrix_R = new_matrix(a*a, 2*a-1), **matrix_RR = new_matrix(a*a, a), **work_delta = new_matrix(a, a), **work_gamma = new_matrix(a, a);

  //work_delta, work_gammaの各行が基底をなす
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      work_delta[i][j] = delta[j][i];
      //cout << i << j << "  " << work_delta[i][j] << endl ;
    }
  }
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      work_gamma[i][j] = ideal_1_xHNF[i][j];
      //cout << i << j << "    " << work_gamma[i][j] << endl ;
    }
  }

  //work_deltaの第i行(基底)とwork_gammaの第j行(基底)同士かけ算して
  //行列R(matrix_R[a*i+j][])に収容
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	for(h=0 ; h<a ; h++){
	  matrix_R[a*i+j][k+h] = matrix_R[a*i+j][k+h] + work_delta[i][k]*work_gamma[j][h];  
	}
      }
    }
  }

  //上で代入されたmatrix_Rに定義方程式を代入してyの次数をa未満にする
  for(i=0 ; i<a*a ; i++){
    for(j=2*a-2 ; j>=a ; j--){
      if(matrix_R[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //定義方程式を代入
	  matrix_R[i][j-k] = matrix_R[i][j-k] - matrix_R[i][j]*defined_polynomial[a-k];
	}
	matrix_R[i][j].assign_zero(MODULO);
      }
    }
  }
  
  //上で求めたmatrix_Rのyの次数<aの部分を新たにmatrix_RRとする
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<a ; j++){
      matrix_RR[i][j] = matrix_R[i][j];
    }
  }

  /*
  cout << "matrix_RR =\n" ;
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<a ; j++){
      cout << i << j << "   " << matrix_RR[i][j] << endl ;
    }
  }*/

  

  /******************************間違い*******************************
  //work_deltaの第i行(基底)とwork_gammaの第j行(基底)同士かけ算して
  //行列RR(matrix_R[a*i+j][])に収容
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	matrix_RR[a*i+j][k] = work_delta[i][k]*work_gamma[j][k];
	//cout << i << j << k << "     " << matrix_RR[a*i+j][k] << endl ;
      }
    }
  }
  //確認
  cout << "delta * gamma =\n" ;
  for(i=0 ; i<a*a ; i++)  print_polynomial_x(matrix_RR[i]);
  ******************************間違い*******************************/

  

  //matrix_RRをHNFしてそれをmatrix_Nとする
  Fp_polynomial **matrix_N = new_matrix(a, a);
  HNF(matrix_RR, matrix_N, a*a);
  

  //確認
  /*
  cout << "matrix_N = \n" ;
  for(i=0 ; i<a ; i++) for(j=0 ; j<a ; j++)
    cout << i << j << "  " << matrix_N[i][j] << endl ;
    */  

  //matrix_Nの行列式,逆行列を求める
  Fp_polynomial det_N(ZERO, MODULO);   //, inverse_N[a][a];
  Fp_polynomial **inverse_N = new_matrix(a, a);
  determinant(matrix_N, a, det_N);
  inverse(matrix_N, a, inverse_N);
  //行列P=delta*inverse_N^{T}
  //実際は行列delta, inverse_Nは,ともに行と列を逆にしているので
  //行列Pもそれにあわせて行と列を逆にする
  Fp_polynomial **matrix_P = new_matrix(a, a);
  cout << "matrix_P =\n" ;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	matrix_P[j][i] = matrix_P[j][i] + delta[k][i]*inverse_N[k][j] ;
      }
      cout << i << " , " << j << "   " << matrix_P[i][j] << endl ;
    }
  }
  
  //work_gcd = gcd(gcd(matrix_P), det_N)を求める
  Fp_polynomial work_gcd(ZERO, MODULO);
  work_gcd = det_N;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      work_gcd = gcd(work_gcd, matrix_P[i][j]);
    }
  }
  cout << "det_N = " << det_N << endl ;
  cout << "k( =gcd(gcd(P), h) ) = " << work_gcd << endl ;
  
  //e, W求める
  e = det_N/work_gcd;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      matrix_W[i][j] = matrix_P[i][j]/work_gcd;
    }
  }
  

}
