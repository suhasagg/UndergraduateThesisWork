#! /usr/local/bin/tcsh -f
# LiDIA 利用のプログラムのコンパイル用シェルスクリプト
while($#argv)
g++ -O3 -L/usr/local/lib/LiDIA/i686-pc-linux-gnuaout/g++ -I/usr/local/include/ $1 -lLiDIA -o $1:r.out
shift 
end
