% Init file for Model1angular.slx

%Gravity
g = [0;0;9.81];

%Masses
m0 = 20;
m1 = 10; 
m2 = 10;
m3 = 10; 
m4 = 10;

%angular inertia
j0 = 0.5;
j1 = 1;
j2 = 1;
j3 = 1;
j4 = 1;

%position of manipulators
r = [1; 0; 0;
    0; 1; 0;
    -1; 0; 0;
    0; -1; 0];
%r_init = [1; 0; 0;-1; 0; 0];

%Constraint Matrix
%A = [-eye(3),skew_sm(r(1:3)),eye(3),zeros(3,9);zeros(3),-eye(3),zeros(3),eye(3),zeros(3,6);-eye(3),skew_sm(r(4:6)),zeros(3,6),eye(3),zeros(3);zeros(3),-eye(3),zeros(3,9),eye(3)];

%stiffness
k1 = 100;
k2 = 100;
k3 = 100;
k4 = 100;
kappa1 = 100;
kappa2 = 100;
kappa3 = 100;
kappa4 = 100;

%damping
d1 = 500;
d2 = 500;
d3 = 500;
d4 = 500;
delta1 = 200;
delta2 = 200;
delta3 = 200;
delta4 = 200;




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

