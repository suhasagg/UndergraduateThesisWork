//void HNF(Fp_polynomial *polynomial_x, Fp_polynomial *polynomial_xHNF, 
//           int polynomial_num)
//行列polynomial_x(基底数(行数)=polynomial_num, 列数=a) を入力
//それをHNFしたものを行列polynomial_xHNF(各行が基底)に出力


void HNF(Fp_polynomial **polynomial_x, Fp_polynomial **polynomial_xHNF, int polynomial_num){
  int i, j, k, l, mi, mj;
  Fp_polynomial **work_A = new_matrix(polynomial_num, a), *work_B = new_vector(a);
  Fp_polynomial work_u(ZERO, MODULO), work_v(ZERO, MODULO), work_gcd(ZERO, MODULO), work_a_ik(ZERO, MODULO), work_a_ij(ZERO, MODULO), work_b(ZERO, MODULO), work_q(ZERO, MODULO), work_r(ZERO, MODULO);
  
  //work_A[polynomial_num][a]にpolynomial_xの値を代入
  cout << "ideal_1_x = (in HNF at the beginning of HNF )kokomade ok" << "\n" ;
  for(i=0 ; i<polynomial_num ; i++){
    for(j=0 ; j<a ; j++){
      work_A[i][j] = polynomial_x[i][j];
    }
  }
  
  
  //HNF
  i=a-1, j=polynomial_num-1, l=0;     //step.1//
  for(k=polynomial_num-1 ; k>=0 ; ){
    while(j>0){                       //step.2//      //if(j==0) ->step.4
      j--;
      if(work_A[j][i].is_zero()) continue;     //->step.2   else->step.3
      else{                           //step.3//
	work_a_ij = work_A[j][i];
	work_a_ik = work_A[k][i];
	xgcd(work_gcd, work_u, work_v, work_a_ik, work_a_ij);
	for(mi=0 ; mi<a ; mi++)  work_B[mi] = work_u*work_A[k][mi] + work_v*work_A[j][mi]; 
	for(mi=0 ; mi<a ; mi++)
	  work_A[j][mi] = (work_a_ik/work_gcd)*work_A[j][mi] - (work_a_ij/work_gcd)*work_A[k][mi]; 
	for(mi=0 ; mi<a ; mi++)  work_A[k][mi] = work_B[mi];
      }                                               //->step.2
    }
    work_b = work_A[k][i];           //step.4//
    if(work_b.is_zero()) k++;                  //->step.5  else->following
    else{
      if(k<polynomial_num-1){
	for(mj=k+1 ; mj<polynomial_num ; mj++){
	  div_rem(work_q, work_r, work_A[mj][i], work_b);
	  for(mi=0 ; mi<a ; mi++){
	    work_A[mj][mi] = work_A[mj][mi] - work_q*work_A[k][mi];
	  }
	}
      }
    }                                                 //->step.5
    if(i==l){                        //step.5//
      for(mj=0 ; mj<polynomial_num-k ; mj++){
	for(mi=0 ; mi<a ; mi++){
	  polynomial_xHNF[mj][mi] = work_A[mj+k][mi];
	}
      }
      break;                                         //HNF end;
    }
    else{
      i=i-1;
      k--;
      j=k;
    }                                                //->step.2
  }
  











  /*************************************デバッグ用***********************************
  //HNF
  i=a-1, j=polynomial_num-1, l=0;     //step.1//
  for(k=polynomial_num-1 ; k>=0 ; ){
    while(j>0){                       //step.2//      //if(j==0) ->step.4
      j--;
      if(work_A[j][i]==zero_polynomial) continue;     //->step.2   else->step.3
      else{                           //step.3//
	work_a_ij = work_A[j][i];
	work_a_ik = work_A[k][i];
	xgcd(work_gcd, work_u, work_v, work_a_ik, work_a_ij);
	cout << "gcd, u, v  " << i << j << k <<"\n"; ////////////////////
	cout << work_gcd << "\n" << work_u << "\n" << work_v << "\n" ;  ///////////////////
	for(mi=0 ; mi<a ; mi++){
	  work_B[mi] = work_u*work_A[k][mi] + work_v*work_A[j][mi]; 
	  cout << "work_B[" << mi << "] = \n" << work_B[mi] << "\n" ;   ////////////////////
	}
	for(mi=0 ; mi<a ; mi++){
	  work_A[j][mi] = (work_a_ik/work_gcd)*work_A[j][mi] - (work_a_ij/work_gcd)*work_A[k][mi]; 
	  cout << "work_A[" << j << "][" << mi << "] = \n" << work_A[j][mi] << "\n" ;  ///////////////////
	}	
	for(mi=0 ; mi<a ; mi++){
	  work_A[k][mi] = work_B[mi];
	  cout << "work_A[" << k << "][" << mi << "] = \n" << work_A[k][mi] << "\n" ;  ///////////////////
	}
      }                                               //->step.2
    }
    work_b = work_A[k][i];           //step.4//
    if(work_b==zero_polynomial) k++;                  //->step.5  else->following
    else{
      cout << k <<"ok\n" ;
      if(k<polynomial_num-1){
	for(mj=k+1 ; mj<polynomial_num ; mj++){
	  div_rem(work_q, work_r, work_A[mj][i], work_b);
	  for(mi=0 ; mi<a ; mi++){
	    work_A[mj][mi] = work_A[mj][mi] - work_q*work_A[k][mi];
	  }
	}
      }
    }                                                 //->step.5
    if(i==l){                        //step.5//
      for(mj=0 ; mj<polynomial_num-k ; mj++){
	for(mi=0 ; mi<a ; mi++){
	  cout << j << i << "okend\n" ;
	  polynomial_xHNF[a*mj+mi] = work_A[mj+k][mi];
	}
      }
      break;                                         //HNF end;
    }
    else{
      i=i-1;
      k--;
      j=k;
    }                                                //->step.2
  }
  
  */////////////////////////////////////////////////////////////









  //確認
  /*
  cout << "ideal_1_x = (in HNF at the end of HNF )" << "\n" ;
  for(mj=0 ; mj<polynomial_num ; mj++){
    cout << "ideal_1_[" << mj << "] = \n" ; 
    print_polynomial_x(work_A[mj]);
  }*/

}
