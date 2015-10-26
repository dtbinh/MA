function [rw] = quatrot(q,r)
% Quaternion q based rotation of vector r, e.g. from object-based to world
% frame
rwq = quatmultiply(quatconj(q'),quatmultiply([0 r'],q'))';
rw = rwq(2:4);
end

