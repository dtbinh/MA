clear mat matr

%Timeseries export to txt
modelname = 'CaVirot';
variablename = ManipulatorWrench;


mat = [get(variablename,'Time'),get(variablename,'Data')];

%reduction of elements
[l,w] = size(mat);
for i=1:l
    if(mod(i,10)==1)
            for j=1:w
                matr(floor(i/10)+1,j)=mat(i,j);
            end
    end
end
%Output

if w==2
    dlmwrite(sprintf('%s_%s.txt',modelname,variablename.name),matr,'\t');
else
    dlmwrite(sprintf('%s_%s_tx.txt',modelname,variablename.name),matr(:,[1,2]),'\t');
    dlmwrite(sprintf('%s_%s_ty.txt',modelname,variablename.name),matr(:,[1,3]),'\t');
    dlmwrite(sprintf('%s_%s_rz.txt',modelname,variablename.name),matr(:,[1,7]),'\t');
end