//get_inverse_ideal(Fp_polynomial *ideal_1_xHNF, Fp_polynomial *delta, 
//                  Fp_polynomial *W, Fp_polynomial &e, 
//                  Fp_polynomial *defined_polynomial)
//



void get_inverse_ideal(Fp_polynomial **ideal_1_xHNF, Fp_polynomial **delta, Fp_polynomial **matrix_W, Fp_polynomial &e, Fp_polynomial *defined_polynomial){
  
  int i, j, k, h;

  //�s��delta�ƍs��ideal_1_xHNF����s��R���߂�
  //Fp_polynomial /*matrix_R[a*a][2*a-1],*/  matrix_RR[a*a][a], work_delta[a][a], work_gamma[a][a];
 
  Fp_polynomial **matrix_R = new_matrix(a*a, 2*a-1), **matrix_RR = new_matrix(a*a, a), **work_delta = new_matrix(a, a), **work_gamma = new_matrix(a, a);

  //work_delta, work_gamma�̊e�s�������Ȃ�
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

  //work_delta�̑�i�s(���)��work_gamma�̑�j�s(���)���m�����Z����
  //�s��R(matrix_R[a*i+j][])�Ɏ��e
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	for(h=0 ; h<a ; h++){
	  matrix_R[a*i+j][k+h] = matrix_R[a*i+j][k+h] + work_delta[i][k]*work_gamma[j][h];  
	}
      }
    }
  }

  //��ő�����ꂽmatrix_R�ɒ�`��������������y�̎�����a�����ɂ���
  for(i=0 ; i<a*a ; i++){
    for(j=2*a-2 ; j>=a ; j--){
      if(matrix_R[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //��`����������
	  matrix_R[i][j-k] = matrix_R[i][j-k] - matrix_R[i][j]*defined_polynomial[a-k];
	}
	matrix_R[i][j].assign_zero(MODULO);
      }
    }
  }
  
  //��ŋ��߂�matrix_R��y�̎���<a�̕�����V����matrix_RR�Ƃ���
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

  

  /******************************�ԈႢ*******************************
  //work_delta�̑�i�s(���)��work_gamma�̑�j�s(���)���m�����Z����
  //�s��RR(matrix_R[a*i+j][])�Ɏ��e
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	matrix_RR[a*i+j][k] = work_delta[i][k]*work_gamma[j][k];
	//cout << i << j << k << "     " << matrix_RR[a*i+j][k] << endl ;
      }
    }
  }
  //�m�F
  cout << "delta * gamma =\n" ;
  for(i=0 ; i<a*a ; i++)  print_polynomial_x(matrix_RR[i]);
  ******************************�ԈႢ*******************************/

  

  //matrix_RR��HNF���Ă����matrix_N�Ƃ���
  Fp_polynomial **matrix_N = new_matrix(a, a);
  HNF(matrix_RR, matrix_N, a*a);
  

  //�m�F
  /*
  cout << "matrix_N = \n" ;
  for(i=0 ; i<a ; i++) for(j=0 ; j<a ; j++)
    cout << i << j << "  " << matrix_N[i][j] << endl ;
    */  

  //matrix_N�̍s��,�t�s������߂�
  Fp_polynomial det_N(ZERO, MODULO);   //, inverse_N[a][a];
  Fp_polynomial **inverse_N = new_matrix(a, a);
  determinant(matrix_N, a, det_N);
  inverse(matrix_N, a, inverse_N);
  //�s��P=delta*inverse_N^{T}
  //���ۂ͍s��delta, inverse_N��,�Ƃ��ɍs�Ɨ���t�ɂ��Ă���̂�
  //�s��P������ɂ��킹�čs�Ɨ���t�ɂ���
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
  
  //work_gcd = gcd(gcd(matrix_P), det_N)�����߂�
  Fp_polynomial work_gcd(ZERO, MODULO);
  work_gcd = det_N;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      work_gcd = gcd(work_gcd, matrix_P[i][j]);
    }
  }
  cout << "det_N = " << det_N << endl ;
  cout << "k( =gcd(gcd(P), h) ) = " << work_gcd << endl ;
  
  //e, W���߂�
  e = det_N/work_gcd;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      matrix_W[i][j] = matrix_P[i][j]/work_gcd;
    }
  }
  

}
