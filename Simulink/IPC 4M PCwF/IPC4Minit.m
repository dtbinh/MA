% Init file for Model1angular.slx

%Gravity
g = [0;0;-9.81];

%Masses
m0 = 10;
m1 = 10; 
m2 = 10;
m3 = 10; 
m4 = 10;

%specified masses
m1d = 0.00*m1;
m2d = 0.00*m2;
m3d = 0.00*m3;
m4d = 0.00*m4;

%angular inertia
j0 = 10;
j1 = 10;
j2 = 10;
j3 = 10;
j4 = 10;

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
k1 = 2000;
k2 = 2000;
k3 = 2000;
k4 = 2000;
kappa1 = 10;
kappa2 = 10;
kappa3 = 10;
kappa4 = 10;

%damping
d1 = 70;
d2 = 70;
d3 = 70;
d4 = 70;
delta1 = 9;
delta2 = 9;
delta3 = 9;
delta4 = 9;
Dc = 0;

Kc = 150;
l = [1 1 1 1];


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

