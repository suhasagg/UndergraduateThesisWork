//���� K_xy���̑�����:polynomial_xy(���(������)�̐�:polynomial_num), 
//     ��`������:defined_polynomial
//�o�� polynomial_xy��K_x���ɂ������̂�polynomial_x�Ƃ��ďo��

void Kxy2Kx(Fp_polynomial **polynomial_xy, int polynomial_num, Fp_polynomial **polynomial_x, Fp_polynomial *defined_polynomial){
  int i, j, k;
  Fp_polynomial **work_A = new_matrix(polynomial_num*a, 2*a-1);
 
  //work_A[polynomial_num][a]��polynomial_xy�̒l����
  //����ɂ���ɁAy^1, y^2, ... , y^(a-1) �������̂���� 
  for(i=0 ; i<polynomial_num ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	work_A[a*i+k][j+k] = polynomial_xy[i][j];
      }
    }
  }

  //�m�F
  /*
  for(i=0 ; i<polynomial_num*a ; i++){
    for(j=0 ; j<2*a-1 ; j++){
      //if(work_A[i][j]!=zero_polynomial)
      cout << i << j << "  " << work_A[i][j] << "\n";
    }
  }
  cout << "\n";
  */
  
  //��ő�����ꂽwork_a�ɒ�`��������������y�̎�����a�����ɂ���
  for(i=0 ; i<polynomial_num*a ; i++){
    for(j=2*a-2 ; j>=a ; j--){
      if(work_A[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //��`����������
	  work_A[i][j-k] = work_A[i][j-k] - work_A[i][j]*defined_polynomial[a-k];
	}
	work_A[i][j].assign_zero(MODULO);
      }
    }
  }
  
  //�m�F
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

  //�m�F
  //for(i=0 ; i<polynomial_num*a*a ; i++) cout << i << "  " << polynomial_x[i] << "\n";
}
