syms Sr1 Sr2 m0 m1 m2 J0 J1 J2 f0 t0 f1 t1 f2 t2 Somega2 r1 r2 real
 A = [-1 Sr1 1 0 0 0; 0 -1 0 1 0 0; -1 Sr2 0 0 1 0; 0 -1 0 0 0 1];
 M = blkdiag(m0,J0,m1,J1,m1,J1);
 h_sigma = [f0;t0;f1;t1;f2;t2];
 b = [Somega2*r1;0;Somega2*r2;0];
 

 
 Ared = [-1 Sr2-Sr1 1 0; 0 -1 0 1];
 Mred = blkdiag(m1,J1,m2,J2);
 bred = [Somega2*(r2-r1); 0];
 h_sigmared = [f1;t1;f2;t2];
 
%  asw = b - A/M*h_sigma
% aswred = bred - Ared/Mred*h_sigmared
% 
% h = A'*inv((A/M*A')) * asw
% hred = Ared'*(Ared/Mred*Ared')^-1 *aswred
% hred2 = sqrt(Mred)*pinv(Ared/sqrt(Mred))*aswred
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
G = [1 0 1 0;
     Sr1 1 Sr2 1];
 null(-G)
 
 
 hred = Ared'*(Ared/Mred*Ared')^-1 *Ared/Mred;