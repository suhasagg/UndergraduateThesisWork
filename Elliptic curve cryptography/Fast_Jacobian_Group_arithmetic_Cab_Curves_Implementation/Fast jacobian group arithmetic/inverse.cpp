//void inverse(Fp_polynomial *matrix_A, int matrix_size, Fp_polynomial &*matrix_inverse)
//正方行列matrix_A(サイズ:matrix_size次の行列)からその(逆行列)*det_Aを求め,inverse_Aに代入
//注意 : 逆行列そのものを求めているわけではない

//void determinant(Fp_polynomial *matrix_A, int matrix_size, Fp_polynomial det_A)
//正方行列matrix_A(サイズ:matrix_size次の行列)からその行列式を求め,det_Aに代入


void determinant(Fp_polynomial **matrix_A, int matrix_size, Fp_polynomial &det_A){
  int i, j, k, h;

  if (matrix_size==1){
    det_A = matrix_A[0][0];
    return;
  }
  
  Fp_polynomial work_det(ZERO, MODULO), work_sum(ZERO, MODULO);
  Fp_polynomial **work = new_matrix(matrix_size-1, matrix_size-1);

  //i : det_Aを求める時に展開する時,第i行について展開
  i = matrix_size-1;    //一番下の行について展開(じゃないとダメ)
  for (j=0 ; j<matrix_size ; j++){            //余因子行列生成
    for (k=0 ; k<matrix_size-1 ; k++){
      for (h=0 ; h<j ; h++)   work[k][h] = matrix_A[k][h];
      for (h=j+1 ; h<matrix_size ; h++) work[k][h-1] = matrix_A[k][h];
    }
    
    determinant(work, matrix_size-1, work_det);
    if((i+j)%2==0)  work_sum = work_sum + matrix_A[i][j]*work_det;
    if((i+j)%2!=0)  work_sum = work_sum - matrix_A[i][j]*work_det;
  }
  det_A = work_sum;
}



void inverse(Fp_polynomial **matrix_A, int matrix_size, Fp_polynomial **inverse_A){
  int i, j, k, h;
  Fp_polynomial work_det(ZERO, MODULO);  
  //余因子行列用  work_cofactor
  Fp_polynomial **work_cofactor = new_matrix(matrix_size-1, matrix_size-1);
  
  //与えられた行列matrix_Aの(i,j)成分の余因子行列
  for(i=0 ; i<matrix_size ; i++){
    for(j=0 ; j<matrix_size ; j++){       
      //与えられた行列matrix_Aの(i,j)成分の余因子行列をwork_cofactorに代入
      for(k=0 ; k<i ; k++){
	for(h=0 ; h<j ; h++) work_cofactor[k][h] = matrix_A[k][h];
	for(h=j+1 ; h<matrix_size ; h++) work_cofactor[k][h-1] = matrix_A[k][h];
      }
      for(k=i+1 ; k<matrix_size ; k++){
	for(h=0 ; h<j ; h++) work_cofactor[k-1][h] = matrix_A[k][h];
	for(h=j+1 ; h<matrix_size ; h++) work_cofactor[k-1][h-1] = matrix_A[k][h];
      }
      //matrix_Aの(i,j)成分の余因子行列の行列式*(-1)^(i+j) = 求める逆行列の(j,i)成分とする
      determinant(work_cofactor, matrix_size-1, work_det);
      if((i+j)%2==0)  inverse_A[j][i] = work_det;
      if((i+j)%2!=0)  inverse_A[j][i] = -1*work_det;
    }
  }
}
