function [rw] = quatrot(q,r)
% Quaternion q based rotation of vector r, e.g. from object-based to world
% frame
rwq = quatmultiply((q'),quatmultiply([0 r'],quatconj(q')))';
rw = rwq(2:4);
end

