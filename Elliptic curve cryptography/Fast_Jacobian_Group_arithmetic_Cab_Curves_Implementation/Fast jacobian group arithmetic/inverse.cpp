//void inverse(Fp_polynomial *matrix_A, int matrix_size, Fp_polynomial &*matrix_inverse)
//�����s��matrix_A(�T�C�Y:matrix_size���̍s��)���炻��(�t�s��)*det_A������,inverse_A�ɑ��
//���� : �t�s�񂻂̂��̂����߂Ă���킯�ł͂Ȃ�

//void determinant(Fp_polynomial *matrix_A, int matrix_size, Fp_polynomial det_A)
//�����s��matrix_A(�T�C�Y:matrix_size���̍s��)���炻�̍s�񎮂�����,det_A�ɑ��


void determinant(Fp_polynomial **matrix_A, int matrix_size, Fp_polynomial &det_A){
  int i, j, k, h;

  if (matrix_size==1){
    det_A = matrix_A[0][0];
    return;
  }
  
  Fp_polynomial work_det(ZERO, MODULO), work_sum(ZERO, MODULO);
  Fp_polynomial **work = new_matrix(matrix_size-1, matrix_size-1);

  //i : det_A�����߂鎞�ɓW�J���鎞,��i�s�ɂ��ēW�J
  i = matrix_size-1;    //��ԉ��̍s�ɂ��ēW�J(����Ȃ��ƃ_��)
  for (j=0 ; j<matrix_size ; j++){            //�]���q�s�񐶐�
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
  //�]���q�s��p  work_cofactor
  Fp_polynomial **work_cofactor = new_matrix(matrix_size-1, matrix_size-1);
  
  //�^����ꂽ�s��matrix_A��(i,j)�����̗]���q�s��
  for(i=0 ; i<matrix_size ; i++){
    for(j=0 ; j<matrix_size ; j++){       
      //�^����ꂽ�s��matrix_A��(i,j)�����̗]���q�s���work_cofactor�ɑ��
      for(k=0 ; k<i ; k++){
	for(h=0 ; h<j ; h++) work_cofactor[k][h] = matrix_A[k][h];
	for(h=j+1 ; h<matrix_size ; h++) work_cofactor[k][h-1] = matrix_A[k][h];
      }
      for(k=i+1 ; k<matrix_size ; k++){
	for(h=0 ; h<j ; h++) work_cofactor[k-1][h] = matrix_A[k][h];
	for(h=j+1 ; h<matrix_size ; h++) work_cofactor[k-1][h-1] = matrix_A[k][h];
      }
      //matrix_A��(i,j)�����̗]���q�s��̍s��*(-1)^(i+j) = ���߂�t�s���(j,i)�����Ƃ���
      determinant(work_cofactor, matrix_size-1, work_det);
      if((i+j)%2==0)  inverse_A[j][i] = work_det;
      if((i+j)%2!=0)  inverse_A[j][i] = -1*work_det;
    }
  }
}
