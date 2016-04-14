%init for DIPC reference trajectory.

kv = 20000;
kappav = 20000;
dv = 5000;
deltav = 5000;
mv = 10;
jv = 1;

m0 = 10;
j0 = 1;
g = [0;0;0];

m1 = 10; 
m2 = 10;
m3 = 10; 
m4 = 10;
miv = 10;
j1 = 10;
j2 = 10;
j3 = 10;
j4 = 10;
jiv = 1;

ks = 2000;
ds = 1000; %300
kappas = 2000;   %500
deltas = 1000; %300

r = [1 0 0 0 1 0 -1 0 0 0 -1 0]';
rv = [1 0 0 0 1 0 -1 0 0 0 -1 0]';

%Local Force control
kv = 30;
kpt = 500;
kpr = 500;