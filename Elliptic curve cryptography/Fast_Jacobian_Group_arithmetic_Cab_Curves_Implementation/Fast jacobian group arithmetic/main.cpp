//����:�v���O�������Ő錾���Ă͍s���Ȃ��ϐ� : a, b, MODULO, ZERO
//a, b, MODULO, ZERO�͂��ׂĊO���ϐ��Ƃ��Ē�`����Ă���v���O�������Œ萔�ł���B
// a��b �� C_ab�Ȑ��p�� a��b ��p

//include����t�@�C��
//are_zero.cpp, print_polynomial.cpp, compute_T.cpp, inverse.cpp, Kxy2Kx.cpp, 
//HNF.cpp, get_inverse_ideal.cpp, degree_Cab.cpp, get_minimum_element.cpp, 
//multiply_ideal.cpp, new_array.cpp
//

#include<iostream.h>
#include<LiDIA/Fp_polynomial.h>
#include<LiDIA/polynomial.h>
#include <LiDIA/bigint.h>
#include <LiDIA/bigmod.h>
#include <LiDIA/timer.h>

//C_ab�Ȑ��� a��b �̒�`
int a, b;
bigint MODULO;
polynomial<bigint> ZERO;

#include "new_array.cpp"
#include "are_zero.cpp"
#include "print_polynomial.cpp"
#include "input_def_poly.cpp" 
#include "compute_T.cpp"
#include "inverse.cpp"
#include "input_ideal.cpp"
#include "Kxy2Kx.cpp"
#include "HNF.cpp"
#include "get_inverse_ideal.cpp"
#include "degree_Cab.cpp"
#include "get_minimum_element.cpp"
#include "multiply_ideal.cpp"
#include "semi2reduced.cpp"

int main(){
  ZERO.assign_zero();

  int i, j, k;
  timer elapsed_time;            //���s���Ԍv���p
  elapsed_time.set_print_mode(HMS_MODE);

  //modulo����
  cout << "Input a, b, MODULO\n" ;
  cin >> a >> b >> MODULO ;
  
  //�m�F
  //cout << "a=" << a << "  ,  " << "b=" << b << "  ,  " << "MODULO=" << MODULO << "\n\n";
  
  Fp_polynomial *defined_polynomial = new_vector(a+1);
  input_defined_polynomial(defined_polynomial);
  //�m�F
  /*
  cout << "defined_polynomial = \n" ;
  cout << "(" << defined_polynomial[a] << ")*y^" << a << "\n" ;
  print_polynomial_x(defined_polynomial);
  */
  //��`������(defined_polynomial)����s��T(matrix_T)�����߂�(trace���狁�܂�)
  Fp_polynomial **matrix_T = new_matrix(a, a);
  compute_T(defined_polynomial, matrix_T);
  //�m�F
  /*
  cout << "matrix_T = \n" ;
  for(i=0 ; i<a ; i++)  for(j=0 ; j<a ; j++)
    cout << i << j << "  " << matrix_T[i][j] << "\n" ;
  
  cout << "finished compute_T()\n" ;
  */
  //�s��T(matrix_T)����(�t�s��T*det_T)������,delta[a][a]�ɑ��
  Fp_polynomial **delta = new_matrix(a, a);
  inverse(matrix_T, a, delta);
  //�m�F
  /*
  cout << "(inverse)*(detT) : delta = \n" ;
  for(i=0 ; i<a ; i++)  for(j=0 ; j<a ; j++)
    cout << i << j << "  " << delta[i][j] << "\n" ;
    */  

  //ideal_1����
  Fp_polynomial **ideal_1 = new_matrix(a, a);
  input_ideal(ideal_1);
  //�m�F
  /*
  for(i=0 ; i<a ; i++){
    cout << "ideal[" << i <<  "] =\n" ;
    print_polynomial_x(ideal_1[i]);
  }*/
  
  Fp_polynomial **ideal_1HNF = new_matrix(a, a);
  HNF(ideal_1, ideal_1HNF, a);//////////////////////////////
  cout << "HNF of ideal_1HNF\n";
  for(i=0 ; i<a ; i++)  print_polynomial_x(ideal_1HNF[i]);
  Fp_polynomial **RE_ideal_1 = new_matrix(a, a), RE_ideal_1_e(ZERO, MODULO);
  semi2reduced(ideal_1HNF, defined_polynomial, delta, RE_ideal_1, RE_ideal_1_e);
  //�m�F
  /*
  cout << "reduced ideal_1 = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(RE_ideal_1[i]);
  cout << RE_ideal_1_e << endl ;
  */

  /****************************************/
  //ideal_2����
  Fp_polynomial **ideal_2 = new_matrix(a, a);
  input_ideal(ideal_2);
  //�m�F
  /*
  for(i=0 ; i<a ; i++){
    cout << "ideal_2[" << i << "] = \n" ; 
    print_polynomial_x(ideal_2[i]);
  }*/
  Fp_polynomial **ideal_2HNF = new_matrix(a, a);
  HNF(ideal_2, ideal_2HNF, a);//////////////////////////////
  cout << "HNF of ideal_2HNF\n";
  for(i=0 ; i<a ; i++)  print_polynomial_x(ideal_2HNF[i]);
  Fp_polynomial **RE_ideal_2 = new_matrix(a, a), RE_ideal_2_e(ZERO, MODULO);
  semi2reduced(ideal_2HNF, defined_polynomial, delta, RE_ideal_2, RE_ideal_2_e);
  //�m�F
  /*
  cout << "reduced ideal_2 = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(RE_ideal_2[i]);
  cout << RE_ideal_2_e << endl ;
  */
  /*********************************************/


  //---------���s���Ԍv���J�n---------------------
  elapsed_time.start_timer();

  /*********************************************/
  //ideal_1(HNF), ideal_2(HNF)�̐ς��Ƃ�
  Fp_polynomial **ideal_1_2 = new_matrix(a*a, a);
  multiply_ideal(ideal_1HNF, ideal_2HNF, ideal_1_2, defined_polynomial);
  Fp_polynomial **ideal_1_2HNF = new_matrix(a, a);
  HNF(ideal_1_2, ideal_1_2HNF, a*a);//////////////////////////////
  Fp_polynomial **RE_ideal = new_matrix(a, a), RE_ideal_e(ZERO, MODULO);
  semi2reduced(ideal_1_2HNF, defined_polynomial, delta, RE_ideal, RE_ideal_e);
  //�m�F
  cout << "reduced ideal = \n" ;
  for(i=0 ; i<a ; i++)  print_polynomial_x(RE_ideal[i]);
  //cout << RE_ideal_e << endl ;
  /*********************************************/

  //---------���s���Ԍv���I��---------------------
  elapsed_time.stop_timer();
  cout << "elapsed_time =  " ; 
  elapsed_time.print();
  cout << "\n" ;

}
