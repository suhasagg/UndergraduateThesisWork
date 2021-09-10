//定義方程式からtraceを求め,traceからできる行列Tを求める

void compute_T(Fp_polynomial *defined_polynomial, Fp_polynomial **matrix_T){
  int i, j, k;
  Fp_polynomial *trace = new_vector(2*a-1), *work_D = new_vector(a);
  Fp_polynomial **work_C = new_matrix(a-1, 2*a-2);     //C[i][l] = C_{l}^{i}

  //行列D生成
  for(i=0 ; i<a ; i++)  work_D[i] = -1*defined_polynomial[i];
  //行列C生成
  //defined_polynomial の右辺 (y^a = ......  )に 
  //y^0, y^1, y^2, ... , y^(a-2) をかけたものを   
  //work_C[0], work_C[1], work_C[2], ... , work_C[a-2] に代入 
  for(i=0 ; i<a-1 ; i++){
    for(j=0 ; j<=a-1 ; j++){
      work_C[i][i+j] = -1*defined_polynomial[j];
    }
  }
  //確認
  /*
  for(i=0 ; i<a-1 ; i++)  for(j=0 ; j<2*a-2 ; j++)
    cout << i << j << "  " << work_C[i][j] << "\n";
  cout << "\n";*/
  
  //上で代入されたwork_Cに定義方程式を代入してyの次数をa未満にする
  for(i=0 ; i<a-1 ; i++){          //i=1～にしてよい
    for(j=2*a-3 ; j>=a ; j--){
      if(work_C[i][j].is_zero())  continue;
      else{
	for(k=1 ; k<=a ; k++){             //定義方程式を代入
	  work_C[i][j-k] = work_C[i][j-k] - work_C[i][j]*defined_polynomial[a-k];
	}
	work_C[i][j].assign_zero(MODULO);
      }
    }
  }
  //確認
  /*
  for(i=0 ; i<a-1 ; i++)  for(j=0 ; j<2*a-2 ; j++)
      cout << i << j << "  " << work_C[i][j] << "\n";
      */

  //Traceを計算  trace[i] は trace[y^i] を表す
  trace[0].set_coefficient(a, 0);   //trace[0] = a とする;
  trace[1] = work_D[a-1];
  for(i=2 ; i<=a-1 ; i++){
    trace[i] = i*work_D[a-i] ;
    for(k=1 ; k<=i-1 ; k++){
      trace[i] = trace[i] + work_D[a-k]*trace[i-k];
    }
  }
  for(i=a ; i<=2*a-2 ; i++){
    for(k=0 ; k<=a-1 ; k++){
      trace[i] = trace[i] + work_C[i-a][k]*trace[k];
    }
  }
  
  //確認
  for(i=0 ; i<=2*a-2 ; i++) cout << "trace[" << i << "]=  " << trace[i] << "\n";
  
  //行列T(matrix_T)生成
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      matrix_T[i][j] = trace[i+j];
    }
  }

}
