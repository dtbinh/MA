clear mat matr

%%Timeseries export to txt
modelname = 'StrIPCrot';
variablename = [errOrient,errAngVel,ManipulatorWrench,InternalWrench];

for k=1:length(variablename)
mat = [get(variablename(k),'Time'),get(variablename(k),'Data')];

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
    dlmwrite(sprintf('%s_%s.txt',modelname,variablename(k).name),matr,'\t');
    copyfile(sprintf('%s_%s.txt',modelname,variablename(k).name),'/home/mangerer/MAgit/MA/Latex/plotdata/');
else
    dlmwrite(sprintf('%s_%s_tx.txt',modelname,variablename(k).name),matr(:,[1,2]),'\t');
    copyfile(sprintf('%s_%s_tx.txt',modelname,variablename(k).name),'/home/mangerer/MAgit/MA/Latex/plotdata/');
    dlmwrite(sprintf('%s_%s_ty.txt',modelname,variablename(k).name),matr(:,[1,3]),'\t');
    copyfile(sprintf('%s_%s_ty.txt',modelname,variablename(k).name),'/home/mangerer/MAgit/MA/Latex/plotdata/');
    dlmwrite(sprintf('%s_%s_rz.txt',modelname,variablename(k).name),matr(:,[1,7]),'\t');
    copyfile(sprintf('%s_%s_rz.txt',modelname,variablename(k).name),'/home/mangerer/MAgit/MA/Latex/plotdata/');
end
end

%% Write handles for .tex file
yaxistext = {'$\Phi_z$ [rad]','$\omega_z$ [rad/s]','$f$[N],$m$[Nm]','$f$[N],$m$[Nm]'};
legendtext = {'error orientation $\Delta \Phi_z$','error angular velocity $\Delta \omega_z$','force $f_x$, force $f_y$, torque $m_z$','force $f_{int,x}$, force $f_{int,y}$, torque $m_{int,z}$'};

fid = fopen(sprintf('%s.tex',modelname),'w');
for k=1:length(variablename)
fprintf(fid,'\\begin{tikzpicture} \n \\begin{axis} [ \n ylabel = {%s}, \n xlabel = {$t$[s]}, \n minor y tick num = 1, \n axis lines = left, \n',yaxistext{k});
mat = [get(variablename(k),'Time'),get(variablename(k),'Data')];
[l,w] = size(mat);
if w==2
    fprintf(fid,'legend entries = {%s}, \n',legendtext{k});
    fprintf(fid,'legend columns=-1, \n legend style = {at={(0.5,1.1)},anchor=south,column sep=1ex,}, legend cell align=left, grid=major, height=5cm, width=0.98\\linewidth \n ]\n');
    fprintf(fid,'\\addplot[red,] table {/home/mangerer/MAgit/MA/Latex/plotdata/%s_%s.txt}; \n',modelname,variablename(k).name);
else
    fprintf(fid,'legend entries = {%s}, \n',legendtext{k});
    fprintf(fid,'legend columns=-1, \n legend style = {at={(0.5,1.1)},anchor=south,column sep=1ex,}, legend cell align=left, grid=major, height=5cm, width=0.98\\linewidth \n ]\n');
    fprintf(fid,'\\addplot[red,] table {/home/mangerer/MAgit/MA/Latex/plotdata/%s_%s_tx.txt}; \n',modelname,variablename(k).name);
    fprintf(fid,'\\addplot[blue,] table {/home/mangerer/MAgit/MA/Latex/plotdata/%s_%s_ty.txt}; \n',modelname,variablename(k).name);
    fprintf(fid,'\\addplot[green,] table {/home/mangerer/MAgit/MA/Latex/plotdata/%s_%s_rz.txt}; \n',modelname,variablename(k).name);
end
fprintf(fid,'\\end{axis} \n');
fprintf(fid,'\\end{tikzpicture} \n\n');
end
fclose(fid);
copyfile(sprintf('%s.tex',modelname),'/home/mangerer/MAgit/MA/Latex/Thesis/');

