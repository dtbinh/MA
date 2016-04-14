% Init file for Model1angular.slx

%Gravity
g = [0;0;-9.81];

alpha = 1.5;
%Masses
m0 = 1.4;
m1 = 2; 
m2 = 2;
m3 = 2; 
m4 = 2;

%specified masses
m1d = 1.00*m1;
m2d = 1.00*m2;
m3d = 1.00*m3;
m4d = 1.00*m4;

%angular inertia
j0 = 0.03;
j1 = 2;
j2 = 2;
j3 = 2;
j4 = 2;

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
k1 = 400;
k2 = 400;
k3 = 400;
k4 = 400;
kappa1 = 2;
kappa2 = 2;
kappa3 = 2;
kappa4 = 2;
K_o = 700;
kappa_o = 5;

%damping
d1 = 1000;
d2 = 1000;
d3 = 1000;
d4 = 1000;
delta1 = 80;
delta2 = 80;
delta3 = 80;
delta4 = 80;
%Dc = 0;
Do = 1500;
deltao = 10;

%Kc = 150;
l = [1 1 1 1];

kvt = 192;
kvr = 14;
kpr = 150;
kpt = 50;

set_param('CaccavaleVillani','AlgebraicLoopSolver','TrustRegion')

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

