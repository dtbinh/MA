% Init file for Model1angular.slx

%Gravity
g = [0;0;-9.81];

alpha = 2;
%Masses
m0 = 10;
m1 = 10; 
m2 = 10;
m3 = 10; 
m4 = 10;

%specified masses
m1d = 1.00*m1;
m2d = 1.00*m2;
m3d = 1.00*m3;
m4d = 1.00*m4;

%angular inertia
j0 = 1;
j1 = 1;
j2 = 1;
j3 = 1;
j4 = 1;

%specified angular inertia
j1d = 1.00*j1;
j2d = 1.00*j2;
j3d = 1.00*j3;
j4d = 1.00*j4;

%position of manipulators
r = [1; 0; 0;
    0; 1; 0;
    -1; 0; 0;
    0; -1; 0];
%r_init = [1; 0; 0;-1; 0; 0];

%Constraint Matrix
%A = [-eye(3),skew_sm(r(1:3)),eye(3),zeros(3,9);zeros(3),-eye(3),zeros(3),eye(3),zeros(3,6);-eye(3),skew_sm(r(4:6)),zeros(3,6),eye(3),zeros(3);zeros(3),-eye(3),zeros(3,9),eye(3)];

%stiffness
k1 = 10000;
k2 = 10000;
k3 = 10000;
k4 = 10000;
kappa1 = 250;
kappa2 = 250;
kappa3 = 250;
kappa4 = 250;
K_o = 10000;
kappa_o = 10000;

%damping
d1 = 100;
d2 = 100;
d3 = 100;
d4 = 100;
delta1 = 100;
delta2 = 100;
delta3 = 100;
delta4 = 100;
Dc = 0;
Do = 2000;
deltao = 2000;

Kc = 150;
l = [1 1 1 1];

kv = 300;
kpr = 10000;
kpt = 50000;


%constrained system damping
%dcs22 = delta1+delta2+skew_sm(r(1:3))*d1*eye(3)*skew_sm(r(1:3))'+skew_sm(r(4:6))*d2*eye(3)*skew_sm(r(4:6))';
%Dcs = [(d1+d2)*eye(3) d1*skew_sm(r(1:3))'+d2*skew_sm(r(4:6))'; d1*skew_sm(r(1:3))+d2*skew_sm(r(4:6)) dcs22];





%contrained stiffness matrix
%Kcs = [k1*eye(3) zeros(3) k2*eye(3) zeros(3); k1*skew_sm(r(1:3))' u*2*kappa1*eye(3) k2*skew_sm(r(1:3)) u*2*kappa2*eye(3)];

%Apparent Inertia
%my22 = j0+j1+j2+skew_sm(r(1:3))*m1*eye(3)*skew_sm(r(1:3))'+skew_sm(r(4:6))*m2*eye(3)*skew_sm(r(4:6))';
%My = [(m0+m1+m2)*eye(3) m1*skew_sm(r(1:3))'+m2*skew_sm(r(4:6))';m1*skew_sm(r(1:3))+m2*skew_sm(r(4:6)) my22];


%Graps matrix
%G = [eye(3) zeros(3) eye(3) zeros(3); skew_sm(r(1:3)) eye(3) skew_sm(r(4:6)) eye(3)];

%generalized inverse grasp matrix
%G_Mplus = [m1/m0*eye(3) (m1/j0*skew_sm(r(1:3)))';zeros(3) j1/j0*eye(3);m2/m0*eye(3) (m2/j0*skew_sm(r(4:6)))';zeros(3) j2/j0*eye(3)];

