//Fp_polynomial�^�̓�d�z��(�s��):matrix[row][column]��
// (**matrix)(�|�C���^�̃|�C���^)�Œ�`��,
//new�ŗ̈�m�ۂ�,����0�ŏ�����,mod��MODULO�̒l�ɐݒ肷��B
//���� : �s��̍s��, ��
//�o�� : �m�ۂ����s��̐擪���w���|�C���^

Fp_polynomial **new_matrix(int n1, int n2){
  int i;
  Fp_polynomial **answer;
  answer = new (Fp_polynomial *) [n1];
  for(i=0 ; i<n1 ; i++)  answer[i] = new Fp_polynomial [n2](ZERO, MODULO);
  return answer;
}



Fp_polynomial *new_vector(int n1){
  Fp_polynomial *answer;
  answer = new Fp_polynomial [n1](ZERO, MODULO);
  return answer;
}



/********************      �g����      ***************/
