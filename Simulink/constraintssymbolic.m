syms jbx mbx jby mby jbz mbz jix mix jiy miy jiz miz pbix pbiy pbiz real

jb = [jbx 0 0; 0 jby 0; 0 0 jbz];
mb = [mbx 0 0; 0 mby 0; 0 0 mbz];
ji = [jix 0 0; 0 jiy 0; 0 0 jiz];
mi = [mix 0 0; 0 miy 0; 0 0 miz];
pbi = [0 -pbiz pbiy; pbiz 0 -pbix; -pbiy pbix 0];


S = [eye(3) zeros(3);
    zeros(3) eye(3);
    ji*jb^-1 zeros(3);
    mi*pbi*jb^-1 mi*mb^-1];

M = [jb zeros(3) zeros(3) zeros(3);
    zeros(3) mb zeros(3) zeros(3);
    zeros(3) zeros(3) ji zeros(3);
    zeros(3) zeros(3) zeros(3) mi];

M^-1*S
S'*M^-1*S
(S'*M^-1*S)^-1
