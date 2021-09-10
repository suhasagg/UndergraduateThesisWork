//入力 Fp_polynomial matrix_W[a][a]
//出力 Fp_polynomial f[a]
//


void get_minimum_element(Fp_polynomial **matrix_W, Fp_polynomial *f){
  //int i, j, k, h, n, counter, position_g[j], /*deg_x,*/ position_g[k], position_temp;
  //int deg_g[j], deg_g[k], deg_temp, deg_compare;
  int i, j, k, h, n, counter, position_temp;
  int deg_temp, deg_compare;
  int deg_f[a], deg_g[a], position_f[a], position_g[a];

  //bigint deg_g[j], deg_g[k], deg_temp, deg_compare;
  //bigint work_r;
  bigmod work_r;  work_r.set_modulus(MODULO);
  Fp_polynomial **work_g = new_matrix(a, a), *work_temp = new_vector(a), work_x(ZERO, MODULO);
  
  /*
  for(i=0 ; i<a ; i++){
    for(j=0 ; j<a ; j++){
      cout << "matrix_W[" << i << "][" << j << "] = " << matrix_W[i][j] << "\n" ;
    }
  }*/

  //step.6でorthogonality defectと比較する用
  //for(i=2 ; i<a ; i++)  degree_Cab(matrix_W[i], deg_f[i], position_f[i]);

  for(i=0 ; i<a ; i++)  work_g[0][i] = matrix_W[0][i];     //step.1
  k=1;
  for(;;){
    for(i=0 ; i<a ; i++)  work_g[k][i] = matrix_W[k][i];   //step.2
    for(;;){           //counter==0になるまで繰り返す
      counter=0;
      cout << "counter = " << counter << "  g[j], g[k] =\n" ;      ////////////////////
      for(j=0 ; j<k ; j++){                            //step.3
	print_polynomial_x(work_g[j]);   //////////////////////////
	//cout << work_g[j][0].lead_coeff() << " leading coefficient\n" ;  /////////
	print_polynomial_x(work_g[k]);   //////////////////////////
	degree_Cab(work_g[j], deg_g[j], position_g[j]);
	degree_Cab(work_g[k], deg_g[k], position_g[k]);
	cout << "deg_g[j], [k] = " << deg_g[j] << " , " << deg_g[k] << "\n" ;
	cout << "position_g[j], [k] = " << position_g[j] << " , " << position_g[k] << "\n" ;

	//if((deg_g[j]-deg_g[k])%a==0){
	if((deg_g[j]-deg_g[k])%a==0 && are_zero(work_g[j])==0 && are_zero(work_g[k])==0){
	  counter = counter + 1;                       //step.5
	  if(deg_g[j]>deg_g[k]){
	    for(h=0 ; h<a ; h++)  work_temp[h] = work_g[k][h];
	    for(h=0 ; h<a ; h++)  work_g[k][h] = work_g[j][h];
	    for(h=0 ; h<a ; h++)  work_g[j][h] = work_temp[h];
	    deg_temp = deg_g[k];
	    deg_g[k] = deg_g[j];
	    deg_g[j] = deg_temp;
	    position_temp = position_g[k];
	    position_g[k] = position_g[j];
	    position_g[j] = position_temp;
	  }
	  cout << "position_g[j], k = " << position_g[j] << "  " << position_g[k] << "\n" ;
	  cout << work_g[j][position_g[j]].lead_coeff() << " leading coefficient of g[j]\n" ; 
	  cout << work_g[k][position_g[k]].lead_coeff() << " leading coefficient of g[k]\n" ;

	  work_r = (bigmod)(work_g[k][position_g[k]].lead_coeff())/(bigmod)(work_g[j][position_g[j]].lead_coeff());
	  cout << "work_r = " << work_r << endl ;      ////////////////////////
	  work_x.assign_zero(MODULO);
	  work_x.set_coefficient(mantissa(work_r), (work_g[k][position_g[k]].degree())-(work_g[j][position_g[j]].degree()));

	  if(work_g[k][position_g[k]].degree()==-1 || work_g[j][position_g[j]].degree()==-1){
	    cout << "damedame in get_minimum_element.cpp\n" ;
	    exit(0);
	  }
	  
	  cout << "work_x = " << work_x << endl ; 
	  for(h=0 ; h<a ; h++)  work_g[k][h] = work_g[k][h] - work_x*work_g[j][h];
	  cout << "work_g[k] = \n" ;
	  print_polynomial_x(work_g[k]);   //////////////////////////
	  //step.6

	  
	}
      }
      if(counter==0)  break;
    }
  
    k=k+1;     //step.4に行く前のstep.3
    if(k==a)  break;    //->step.4'
  }
  
  
  degree_Cab(work_g[0], deg_compare, position_temp);         //step.4'
  for(n=0 ; n<a ; n++)  f[n] = work_g[0][n];
  deg_temp = deg_compare;
  for(h=1 ; h<a ; h++){
    degree_Cab(work_g[h], deg_compare, position_temp);
    if(deg_compare < deg_temp){
      for(n=0 ; n<a ; n++)  f[n] = work_g[h][n];
      deg_temp = deg_compare;
    }
  }

}
