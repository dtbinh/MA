function [ vrot ] = aarot( v1,v2,v3 )
%Axis Angle based rotation function, v1 and v2 define the axis and the
%angle of rotation, v3 is rotated

%Calculate axis and angle for rotation
axis = (skew_sm(v1)*v2)/norm(skew_sm(v1)*v2);
cosa = dot(v1,v2)/norm(v1)/norm(v2);
sina = norm(skew_sm(v1)*v2)/norm(v1)/norm(v2);

%Rodrigues formula
vrot = cosa*v3 + sina*(skew_sm(axis)*v3) + (1-cosa)*dot(axis,v3)*axis;

end

