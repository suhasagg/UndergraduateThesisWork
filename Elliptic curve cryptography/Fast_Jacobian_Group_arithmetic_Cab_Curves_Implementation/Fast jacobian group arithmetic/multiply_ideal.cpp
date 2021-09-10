//����:�Q�̃C�f�A�� ideal_1[a][a], ideal_2[a][a] (�����Ƃ����̐� = a), 
//��`������:defined_polynomial[a+1]
//�o��:ideal_1, ideal_2�̐ς���ł���C�f�A�� ideal_product[a*a][a]

//void multiply_ideal(Fp_polynomial *ideal_1, Fp_polynomial *ideal_2, Fp_polynomial *ideal_product, Fp_polynomial *defined_polynomial){

void multiply_ideal(Fp_polynomial **ideal_1, Fp_polynomial **ideal_2, Fp_polynomial **ideal_product, Fp_polynomial *defined_polynomial){
  int i, j, k, h;
  Fp_polynomial **work = new_matrix(a*a, 2*a-1);
  /*
  Fp_polynomial work[a*a][2*a-1];
  //0�ŏ�����
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<2*a-1 ; j++){
      work[i][j].assign_zero(MODULO);
    }
  }*/

  //ideal_1�̑�i�s(���)��ideal_2�̑�j�s(���)���m�����Z����
  //�s��:work[a*i+j][]�Ɏ��e
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	for(h=0 ; h<a ; h++){
	  work[a*i+j][k+h] = work[a*i+j][k+h] + ideal_1[i][k]*ideal_2[j][h];  
	}
      }
    }
  }

  //��Ōv�Z���ꂽ�s��work�ɒ�`��������������y�̎�����a�����ɂ���
  for(i=0 ; i<a*a ; i++){
    for(j=2*a-2 ; j>=a ; j--){
      if(work[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //��`����������
	  work[i][j-k] = work[i][j-k] - work[i][j]*defined_polynomial[a-k];
	}
	work[i][j].assign_zero(MODULO);
      }
    }
  }
  
  //��ŋ��߂�work��y�̎���<a�̕�����V����workR�Ƃ���
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<a ; j++){
      ideal_product[i][j] = work[i][j];
    }
  }



}
