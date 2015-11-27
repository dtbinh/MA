mu = 0.55;

setlmis([])
%Matrix variable
[X11,n,sX11] = lmivar(1,[3 0]);
[X12,n,sX12] = lmivar(1,[3 0]);
[X13,n,sX13] = lmivar(1,[3 0]);
[X1,n,sX1] = lmivar(3,[sX11 sX12 sX13]);

[X21,n,sX21] = lmivar(1,[3 0]);
[X22,n,sX22] = lmivar(1,[3 0]);
[X23,n,sX23] = lmivar(1,[3 0]);
[X2,n,sX2] = lmivar(3,[sX21 sX22 sX23]);

[X,n,sX] = lmivar(3,[sX1 zeros(3,9); zeros(3,9) sX2]);

%Friction Constraints: PCwF
S1 = [0 0 1; 0 0 0; 1 0 0; 0 0 0; 0 0 1; 0 1 0; mu*eye(3)];
S2 = [0 0 1; 0 0 0; 1 0 0; 0 0 0; 0 0 1; 0 1 0; mu*eye(3)];
S = [S1 zeros(9,3); zeros(9,3) S2];

%Matrix term
PCwF = newlmi;
lmiterm([PCwF 1 1 X],-1,S)

LMIsys = getlmis;

K = decnbr(LMIsys)

[copt,xopt] = mincx(LMIsys,[0 0 1 0 0 1])