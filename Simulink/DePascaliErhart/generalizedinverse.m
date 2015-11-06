syms x1 x2 x3 x4 y1 y2 y3 y4 z1 z2 z3 z4 real
S1 = [0 -z1 y1; z1 0 -x1; -y1 x1 0];
S2 = [0 -z2 y2; z2 0 -x2; -y2 x2 0];
S3 = [0 -z3 y3; z3 0 -x3; -y3 x3 0];
S4 = [0 -z4 y4; z4 0 -x4; -y4 x4 0];
J4 = eye(3) + 0.25*(S2*S2' + S1*S1' + S3*S3' + S4*S4');
J4inv = J4^-1;