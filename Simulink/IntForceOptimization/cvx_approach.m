mu = 1;
%Internal Force Optimization based on Han, Trinkle, Li Apprach;
%Optimization with CVX Matlab Software for Disciplined Convex Programming
cvx_begin
variable x(6)
S1 = [0 0 1; 0 0 0; 1 0 0; 0 0 0; 0 0 1; 0 1 0; mu*eye(3)];
S2 = [0 0 1; 0 0 0; 1 0 0; 0 0 0; 0 0 1; 0 1 0; mu*eye(3)];
S1(1:3,:)*x(1) + S1(4:6,:)*x(2) + S1(7:9,:)*x(3) >= 0; 
S2(1:3,:)*x(4) + S2(4:6,:)*x(5) + S2(7:9,:)*x(6) >= 0;
P = blkdiag(S1(1:3,:)*x(1) + S1(4:6,:)*x(2) + S1(7:9,:)*x(3),S2(1:3,:)*x(4) + S2(4:6,:)*x(5) + S2(7:9,:)*x(6));

minimize([0 0 1 0 0 1]*x + inv_pos(log_det(P)))
cvx_end

x