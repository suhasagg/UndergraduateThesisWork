//入力:２つのイデアル ideal_1[a][a], ideal_2[a][a] (両方とも基底の数 = a), 
//定義方程式:defined_polynomial[a+1]
//出力:ideal_1, ideal_2の積からできるイデアル ideal_product[a*a][a]

//void multiply_ideal(Fp_polynomial *ideal_1, Fp_polynomial *ideal_2, Fp_polynomial *ideal_product, Fp_polynomial *defined_polynomial){

void multiply_ideal(Fp_polynomial **ideal_1, Fp_polynomial **ideal_2, Fp_polynomial **ideal_product, Fp_polynomial *defined_polynomial){
  int i, j, k, h;
  Fp_polynomial **work = new_matrix(a*a, 2*a-1);
  /*
  Fp_polynomial work[a*a][2*a-1];
  //0で初期化
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<2*a-1 ; j++){
      work[i][j].assign_zero(MODULO);
    }
  }*/

  //ideal_1の第i行(基底)とideal_2の第j行(基底)同士かけ算して
  //行列:work[a*i+j][]に収容
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      for(k=0 ; k<a ; k++){
	for(h=0 ; h<a ; h++){
	  work[a*i+j][k+h] = work[a*i+j][k+h] + ideal_1[i][k]*ideal_2[j][h];  
	}
      }
    }
  }

  //上で計算された行列workに定義方程式を代入してyの次数をa未満にする
  for(i=0 ; i<a*a ; i++){
    for(j=2*a-2 ; j>=a ; j--){
      if(work[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //定義方程式を代入
	  work[i][j-k] = work[i][j-k] - work[i][j]*defined_polynomial[a-k];
	}
	work[i][j].assign_zero(MODULO);
      }
    }
  }
  
  //上で求めたworkのyの次数<aの部分を新たにworkRとする
  for(i=0 ; i<a*a ; i++){
    for(j=0 ; j<a ; j++){
      ideal_product[i][j] = work[i][j];
    }
  }



}
