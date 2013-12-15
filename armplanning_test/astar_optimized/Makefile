all:
	g++ -D COSTFUNCTION=0 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_basic
	g++ -D COSTFUNCTION=1 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_noalpha
	g++ -D COSTFUNCTION=2 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench
basic:
	g++ -D COSTFUNCTION=0 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_basic
noalpha:
	g++ -D COSTFUNCTION=1 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_noalpha
wrench:
	g++ -D COSTFUNCTION=2 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench
fake:
	g++ -D COSTFUNCTION=3 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_fake

clean:
	rm astar_basic
	rm astar_noalpha
	rm astar_wrench


