//Fp_polynomial型の二重配列(行列):matrix[row][column]を
// (**matrix)(ポインタのポインタ)で定義し,
//newで領域確保し,かつ0で初期化,modをMODULOの値に設定する。
//入力 : 行列の行数, 列数
//出力 : 確保した行列の先頭を指すポインタ

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



/********************      使い方      ***************/
