function zopt = cvx_routine(h_xcn,mu)

S1 = [0 0 1; 0 0 0; 1 0 0; 0 0 0; 0 0 1; 0 1 0; mu*eye(3)]; %Friction constraint matrices
S2 = [0 0 1; 0 0 0; 1 0 0; 0 0 0; 0 0 1; 0 1 0; mu*eye(3)];

cvx_begin sdp
cvx_solver mosek
variable z(1) %Declare internal forces z to optimize
x = h_xcn + [0 0 1 0 0 1]'*z; %External and internal forces

% S1(1:3,:)*x(1) + S1(4:6,:)*x(2) + S1(7:9,:)*x(3) >= 0; %Friction constraint inequalities
% S2(1:3,:)*x(4) + S2(4:6,:)*x(5) + S2(7:9,:)*x(6) >= 0;
(blkdiag(S1(1:3,:)*x(1) + S1(4:6,:)*x(2) + S1(7:9,:)*x(3),S2(1:3,:)*x(4) + S2(4:6,:)*x(5) + S2(7:9,:)*x(6))) >= 0;
P = blkdiag(S1(1:3,:)*x(1) + S1(4:6,:)*x(2) + S1(7:9,:)*x(3),S2(1:3,:)*x(4) + S2(4:6,:)*x(5) + S2(7:9,:)*x(6));

minimize([0 0 1 0 0 1]*x + inv_pos(log_det(P))) %minimize z in cost function
cvx_end
zopt = z;

