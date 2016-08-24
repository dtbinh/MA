%init for DIPC reference trajectory.

kv = 700;
dv = 1500;
kappav = 400; %650
deltav = 500; %650

mv = 1.4;
jv = 0.2;

m0 = 1.4;
j0 = 0.2;
g = [0;0;0];

m1 = 10; 
m2 = 10;
m3 = 10; 
m4 = 10;
miv = 10;
j1 = 0.5;
j2 = 0.5;
j3 = 0.5;
j4 = 0.5;
jiv = 0.5;

ks = 120; %90
ds = ks*5; %300
kappas = ks/20;   %500
deltas = ds/20; %300

r  = 0.4*[0 1 0, 1 0 0, 0 -1 0, -1 0 0]';
rv = 0.4*[0 1 0, 1 0 0, 0 -1 0, -1 0 0]';

%Local Force control
kvt = 5000;
kvr = 1500;
kpt = 500; %500
kpr = 200; %200