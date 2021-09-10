//���� : **ideal, *defined_polynomial, **delta
//�o�� : **reduced_ideal, &reduced_ideal_e
//ideal(semi-reduced)����reduced-ideal�����߂�


void semi2reduced(Fp_polynomial **ideal, Fp_polynomial *defined_polynomial, Fp_polynomial **delta, Fp_polynomial **reduced_ideal, Fp_polynomial &reduced_ideal_e){
  int i, j;

  //Algorithm.5  �t�C�f�A�������߂�
  Fp_polynomial e(ZERO, MODULO), **matrix_W = new_matrix(a, a);
  get_inverse_ideal(ideal, delta, matrix_W, e, defined_polynomial);

  //�m�F
  cout << "e = " << e <<"\n" ;
  cout << "matrix_W = \n" ;
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      cout << i << j << "     " << matrix_W[i][j] <<"\n" ;
    }
  }

  //�m�F : W�����͂��ꂽ�C�f�A��(ideal)�̋t�C�f�A���ɂȂ��Ă��邩�ǂ����̊m�F
  //�C�f�A��ideal�ƃC�f�A���Ƃ̃C�f�A���ς��v�Z���Ă����ideal_prdctW�Ƃ���
  Fp_polynomial **ideal_prdctW = new_matrix(a*a ,a);
  multiply_ideal(ideal, matrix_W, ideal_prdctW, defined_polynomial);
  
  cout << "kakunin of inverse_ideal W\n" ;
  for(i=0 ; i<a*a ; i++){
    print_polynomial_x(ideal_prdctW[i]);
    cout << endl ;
  }

  Fp_polynomial **ideal_prdctWHNF = new_matrix(a, a);
  HNF(ideal_prdctW, ideal_prdctWHNF, a*a);
  //�m�F
  cout << "ideal_prdctWHNF = \n" ;
  for(i=0 ; i<a ; i++){
    print_polynomial_x(ideal_prdctWHNF[i]);
  }
  

  //�s��matrix_W����ŏ���f�����߂�
  Fp_polynomial *f = new_vector(a);
  get_minimum_element(matrix_W, f);
  //�m�F
  cout << "f = \n" ;
  print_polynomial_x(f);

  //�ŏ���f�̊���K_xy����K_x�ɕϊ����Ă����,f_x�ɓ����
  Fp_polynomial **f_x = new_matrix(a, a);
  Fp_polynomial **fff = new_matrix(1, a);   //(*f)��(**fff)�ɒ���
  for(i=0 ; i<a ; i++)  fff[0][i] = f[i];   //Kxy2Kx�̍ŏ��̈����͍s�񂵂��󂯕t���Ȃ�����
  Kxy2Kx(fff, 1, f_x, defined_polynomial);
  //�m�F
  cout << "f_x = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(f_x[i]);

  //�C�f�A��ideal�ƃC�f�A��f_x�Ƃ̐ς��v�Z���Ă����ideal_f_x�Ƃ���
  Fp_polynomial **ideal_f_x = new_matrix(a*a ,a);
  multiply_ideal(ideal, f_x, ideal_f_x, defined_polynomial);
  //�m�F
  cout << "ideal_f_x = \n" ;
  for(i=0 ; i<a*a ; i++)  print_polynomial_x(ideal_f_x[i]);


  /*****************************************************************/
  //����ɂ���(ideal_f_x)�̂��ׂĂ̗v�f�� e �Ŋ��������̂�V����ideal_f_x�Ƃ���
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<a ; j++){
      ideal_f_x[i][j] = ideal_f_x[i][j] / e ;
    }
  } 
  /******************************************************************/
  //��ŋ��߂�ideal_f_x[a*a][a]��HNF
  Fp_polynomial **ideal_f_xHNF = new_matrix(a, a);
  HNF(ideal_f_x, ideal_f_xHNF, a*a);
  //�m�F
  cout << "ideal_f_xHNF = (in main at the end of HNF )" << "\n" ;
  for(i=0 ; i<a ; i++){
    cout << "ideal_f_xHNF[" << i << "] = \n" ;
    print_polynomial_x(ideal_f_xHNF[i]);
  }

  
  //��ŋ��߂�ideal_f_xHNF[a][a] = reduced_ideal �Ƃ���
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      reduced_ideal[i][j] = ideal_f_xHNF[i][j] ;
    }
  }
  //RE_ideal_e = e �Ƃ���
  reduced_ideal_e = e;

  //��ŋ��߂�ideal_f_xHNF[a][a]�̂��ׂĂ̗v�f�� e �Ŋ���
  /*
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      reduced_ideal[i][j] = ideal_f_xHNF[i][j]/e ;
    }
  }
  //�m�F
  cout << "reduced_ideal = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(reduced_ideal[i]);
  */

}
