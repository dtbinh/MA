% Init file for Model1.slx

%Gravity
g = [0;0;-9.81];

%Masses
m0 = 20;
m1 = 10; 
m2 = 10;

%Constraint Matrix
A = [-eye(3),eye(3),zeros(3);-eye(3),zeros(3),eye(3)];

%stiffness
k1 = 1;
k2 = 1;

%damping
d1 = 5;
d2 = 5;

%position of manipulators
r = [1 0 0;-1 0 0];


%Graps matrix
G = [eye(3) eye(3)];

%generalized inverse grasp matrix
G_Mplus = [m1/m0 *eye(3);m2/m0 *eye(3)];

