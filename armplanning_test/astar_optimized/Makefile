all:
	g++ -D COSTFUNCTION=0 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_basic
	g++ -D COSTFUNCTION=1 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_noalpha
	g++ -D COSTFUNCTION=2 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench
	g++ -D COSTFUNCTION=3 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench_noalpha
	g++ -D COSTFUNCTION=4 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench_ratio
	g++ -D COSTFUNCTION=5 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_energy_linear

basic:
	g++ -D COSTFUNCTION=0 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_basic
noalpha:
	g++ -D COSTFUNCTION=1 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_noalpha
wrench:
	g++ -D COSTFUNCTION=2 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench
wrenchnoalpha:
	g++ -D COSTFUNCTION=3 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench_noalpha
wrenchratio:
	g++ -D COSTFUNCTION=4 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_wrench_ratio
energylinear:
	g++ -D COSTFUNCTION=5 -g3 -O3 -msse2 -I../Eigen/ -L../Eigen/Eigen/src planarmpath.cpp forward_kinematics.cpp -o astar_energy_linear

clean:
	rm -f astar_basic
	rm -f astar_noalpha
	rm -f astar_wrench
	rm -f astar_wrench_noalpha
	rm -f astar_wrench_ratio
	rm -f astar_energy_linear

