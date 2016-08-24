\ProvidesClass{ITRslides}[2007/05/31 class for ITR slides]
\typeout{-- 2015/04/17 revision V1.1 by M. Kimmel}
\typeout{-- 2012/11/08 revision V1.0 by B. Weber and D. Althoff}
\typeout{-- 2012/09/27 revision V0.3 by B. Weber}
\typeout{-- 2011/10/05 revision V0.2 by M. Rank}
\typeout{-- 2007/05/31 revision V0.1 by M. Sobotka}
\typeout{-- 2007/05/31 most recent changes by Marion Sobotka}
\typeout{-- Report bugs to da@tum.de stating the version number.}
\NeedsTeXFormat{LaTeX2e}

\pdfminorversion=4 % Melanie: may prevent a problem with figures - I have not been able to recreate that problem

%%%%% Definition of Options
\newif\if@student      \global\@studentfalse
\newif\if@center       \global\@centerfalse
\newif\if@longpres     \global\@longpresfalse
\newif\if@noshadow     \global\@noshadowfalse
\newif\if@linebreak    \global\@linebreakfalse
\newif\if@secondline   \global\@secondlinefalse

\DeclareOption{student}{\@studenttrue}
\DeclareOption{center}{\@centertrue}
\DeclareOption{longpres}{\@longprestrue}
\DeclareOption{noshadow}{\@noshadowtrue}

% Pass through beamer options, e.g. 'handout'
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{beamer}}
\ProcessOptions
\if@center
	\ClassWarningNoLine{ITRslides.cls}{Option 'center' is deprecated}
\fi

%%%%% Beamer class
\LoadClass[hyperref={pdfpagelabels=true}]{beamer}

\let\Tiny=\tiny

%%%%% Packages
\RequirePackage{amsmath}
\RequirePackage{amssymb}
\RequirePackage{graphicx}
\RequirePackage{xcolor}
\RequirePackage{multicol}
\RequirePackage{url}
\RequirePackage{ifxetex}
\RequirePackage{ifpdf}
\RequirePackage{tcolorbox}
\ifxetex	
	\RequirePackage{fontspec}
\else
	\RequirePackage[utf8]{inputenc}
\fi
%\RequirePackage[url=false,citestyle=authoryear,block=ragged,backend=bibtexu]{biblatex}
\RequirePackage[url=false,citestyle=authoryear,block=ragged,backend=bibtexu]{biblatex}

%% for right spacing after itemize
\RequirePackage{enumitem}
\setitemize{noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}
\setlist[itemize,1]{label=\tiny\raise0.4ex\hbox{\donotcoloroutermaths$\blacksquare$}}
\setlist[itemize,2]{label=\tiny\raise0.4ex\hbox{\scalebox{0.8}{\donotcoloroutermaths$\blacksquare$}}}
\setlist[enumerate,1]{label=\arabic*., ref=\arabic*} 
\setlist[enumerate,2]{label=\alph*), ref=\theenumi.\alph*} 


%%%%%% TUM Corporate Design Colors
\definecolor{tum_blue}{rgb} {0.00,0.40,0.74}
\definecolor{tum_dblue}{rgb}{0.00,0.20,0.35}
\definecolor{tum_lblue}{rgb}{0.39,0.63,0.78}
\definecolor{itr_blue}{rgb}{0.63,0.73,0.91}

\definecolor{tum_lgray}{rgb}{0.85,0.85,0.86}
\definecolor{tum_mgray}{rgb}{0.45,0.46,0.46}
\definecolor{tum_gray}{rgb}{0.60,0.61,0.61}
\definecolor{tum_dgray}{rgb}{0.35,0.35,0.35}

\definecolor{tum_red} {rgb}{0.77,0.03,0.09}
\definecolor{tum_dred}{rgb}{0.61,0.05,0.09}
\definecolor{itr_red} {rgb}{0.55,0.00,0.16}

\definecolor{tum_green} {rgb}{0.64,0.68,0.0}
\definecolor{tum_dgreen}{rgb}{0.0,0.49,0.19}
\definecolor{tum_lgreen}{rgb}{0.4,0.60,0.11}

\definecolor{tum_orange}{rgb}{0.89,0.45,0.13}
\definecolor{tum_ivory} {rgb}{0.86,0.84,0.80}
\definecolor{tum_purple}{rgb}{0.41,0.03,0.35}
\definecolor{tum_violet}{rgb}{0.06,0.11,0.37}
\definecolor{tum_yellow}{rgb}{1.00,0.71,0.00}

\ifxetex
	\usefonttheme{professionalfonts} % for keeping math font unchanged
	\setsansfont[   
		ExternalLocation  	= ./fonts/,
		BoldFont          	= TUMNeueHelvetica-Bold,
		ItalicFont        	= TUMNeueHelvetica-Italic,
		BoldItalicFont    	= TUMNeueHelvetica-BoldItalic
		]{TUMNeueHelvetica-Regular}
	%\setmonofont[ExternalLocation=./fonts/]{LTYPE.TTF}
\fi


%%%%% Create Boxes for Presenter, Authors, Supervisor, and Affiliations
\newlength{\bottomlinelen}
\newlength{\blockwidth}	

\if@student
	%\newsavebox{\authorsboxone}
	\def\@varpresenter{leer}
	\newcommand{\presenter}[1]{\def\@varpresenter{\textbf{#1}}}
	\def\@varsupervisor{S. Supervisor}
	\newcommand{\supervisor}[1]{\def\@varsupervisor{#1}}

	\def\@vartypeofpres{Zwischenbericht/Abschlussbericht Diplomarbeit/Studienarbeit}
	\newcommand{\typeofpres}[1]{\def\@vartypeofpres{#1}}
\else
%%%% Scientific Presentation
	\newsavebox{\affilsbox}				% all affiliations
	\newsavebox{\authorsboxone}		% first line of authors
	\newsavebox{\authorsboxtwo}		% second line of authors
	\newbox{\newauthorbox}				% box for current author
	\newlength{\boxlen}
	\newlength{\boxaffillen}
	\newlength{\authorlen}
	\newlength{\maillen}
	\newcount\authornum
	\newlength\firstaffillen
	\newlength\secondaffillen
	\authornum=0
	%%  \presenter[linebreak]{name}{opt: affil}%%{dep: email}%%
	\newcommand{\presenter}[3][\empty]{\presenterwithmail[#1]{#2}{#3}{}}
	\newcommand{\presenterwithmail}[4][\empty]{				%call this for email support !deprecated!
		\ifx#1\empty
			\ifnum\authornum=4
				\@linebreaktrue
			\fi
		\else
			\ifnum\authornum<4
				\@linebreaktrue
			\fi
		\fi
		\settowidth{\authorlen}{\textbf{#2}\textsuperscript{#3}}
		\settowidth{\maillen}{\texttt{\scriptsize #4}}
		\ifdim\authorlen<\maillen
			\boxlen\maillen
		\else
			\boxlen\authorlen
		\fi
		\if@center
			\setbox\newauthorbox\vtop{%	
			 \hbox to \boxlen{\hfil \textbf{#2}\textsuperscript{#3} \hfil}%
				\ifx#4\empty
				\else
					\vskip -2mm
					\hbox to \boxlen{\hfil \texttt{\scriptsize{%
						\ifxetex
							\addfontfeatures{Color=tum_mgray}%
						\else
							\color{tum_mgray}%
						\fi
						#4}}\hfil}
				\fi}
		\else
				\ifx&#4&
						\setbox\newauthorbox\vbox{\hbox to \boxlen{\textbf{\underline{#2}}\textsuperscript{#3}}}
				\else
						\setbox\newauthorbox\vtop{%	
							\hbox to \boxlen{\textbf{\underline{#2}}\textsuperscript{#3} \hfil}%
							\vskip -2mm	
							\hbox to \boxlen{\texttt{\scriptsize{%
									\ifxetex
										\addfontfeatures{Color=tum_mgray}%
									\else
										\color{tum_mgray}%
									\fi
									#4}}\hfil}
								\vskip 5mm
							}
				\fi
		\fi%\if@center
	
	\if@linebreak
		\sbox\authorsboxtwo{\usebox{\newauthorbox}}
		\authornum=5
		\@linebreakfalse
		\@secondlinetrue
	\else
		\ifnum\authornum=4
			\sbox\authorsboxtwo{\usebox{\newauthorbox}}
			\advance\authornum1
			\@linebreakfalse
			\@secondlinetrue
		\else
			\ifnum\authornum=0	
				\sbox\authorsboxone{\usebox{\newauthorbox}}
				\advance\authornum1
			\else
				\ifnum\authornum<4
					\sbox\authorsboxone{\usebox{\authorsboxone}\hspace{5mm}\usebox{\newauthorbox}}
					\advance\authornum1
				\else
					\sbox\authorsboxtwo{\usebox{\authorsboxtwo}\hspace{5mm}\usebox{\newauthorbox}}
					\advance\authornum1
				\fi %\ifnum\authornum<4
			\fi %\ifnum\authornum=0	
		\fi%\ifnum\authornum=4
	\fi%\if@linebreak
	}	
	
	%%  \addauthor[linebreak]{name}{opt: affil}%%{dep: email}%%
	\newcommand{\addauthor}[3][\empty]{\addauthorwithmail[#1]{#2}{#3}{}}
	\newcommand{\addauthorwithmail}[4][\empty]{				%call this for email support !deprecated!
		\ifx#1\empty
			\ifnum\authornum=4
				\@linebreaktrue
			\fi
		\else
			\ifnum\authornum<4
				\@linebreaktrue
			\fi
		\fi
		\settowidth{\authorlen}{\textbf{#2}\textsuperscript{#3}}
		\settowidth{\maillen}{\texttt{\scriptsize #4}}
		\ifdim\authorlen<\maillen
			\boxlen\maillen
		\else
			\boxlen\authorlen
		\fi
		\if@center
			\setbox\newauthorbox\vtop{%	
			 \hbox to \boxlen{\hfil \textbf{#2}\textsuperscript{#3} \hfil}%
				\ifx#4\empty
				\else
					\vskip -2mm
					\hbox to \boxlen{\hfil \texttt{\scriptsize{%
						\ifxetex
							\addfontfeatures{Color=tum_mgray}%
						\else
							\color{tum_mgray}%
						\fi
						#4}}\hfil}
				\fi}
		\else
				\ifx&#4&
						\setbox\newauthorbox\vbox{\hbox to \boxlen{\textbf{#2}\textsuperscript{#3}}}
				\else
						\setbox\newauthorbox\vtop{%	
							\hbox to \boxlen{\textbf{#2}\textsuperscript{#3} \hfil}%
							\vskip -2mm	
							\hbox to \boxlen{\texttt{\scriptsize{%
									\ifxetex
										\addfontfeatures{Color=tum_mgray}%
									\else
										\color{tum_mgray}%
									\fi
									#4}}\hfil}
							\vskip 5mm
							}
				\fi
		\fi%\if@center
	
	\if@linebreak
		\sbox\authorsboxtwo{\usebox{\newauthorbox}}
		\authornum=5
		\@linebreakfalse
		\@secondlinetrue
	\else
		\ifnum\authornum=4
			\sbox\authorsboxtwo{\usebox{\newauthorbox}}
			\advance\authornum1
			\@linebreakfalse
			\@secondlinetrue
		\else
			\ifnum\authornum=0	
				\sbox\authorsboxone{\usebox{\newauthorbox}}
				\advance\authornum1
			\else
				\ifnum\authornum<4
					\sbox\authorsboxone{\usebox{\authorsboxone}\hspace{5mm}\usebox{\newauthorbox}}
					\advance\authornum1
				\else
					\sbox\authorsboxtwo{\usebox{\authorsboxtwo}\hspace{5mm}\usebox{\newauthorbox}}
					\advance\authornum1
				\fi
			\fi
		\fi
	\fi
	}
	
	%%  \addaffiliations[opt: footnote]{line 1}{opt: line 2}
	\newcommand{\addaffiliations}[3][\empty]{
		\settowidth{\firstaffillen}{\textsuperscript{\scriptsize #1}#2}
		\settowidth{\secondaffillen}{#3}
		\ifdim\boxaffillen<\firstaffillen
			\ifdim\firstaffillen<\secondaffillen
				\boxaffillen\secondaffillen
			\else
				\boxaffillen\firstaffillen
			\fi
		\else
			\ifdim\boxaffillen<\secondaffillen
				\boxaffillen\secondaffillen
			\fi
		\fi
	\if@center
		\setbox\affilsbox\vbox{
				\hbox to \boxaffillen{\hfil\usebox{\affilsbox}\hfil}%
				\hbox to \boxaffillen{\hfil\textsuperscript{\scriptsize #1}{\footnotesize #2}\hfil}
				\vskip -1.5mm
				\ifx#3\empty
				\else
					\vskip .5mm
					\hbox to \boxaffillen{\hfil\footnotesize%
							\ifxetex
								\addfontfeatures{Color=tum_mgray}%
							\else
								\color{tum_mgray}%
							\fi
							#3\hfil}\vskip 2mm plus 1mm
				\fi
				}
	\else
		\setbox\affilsbox\vbox{
				\hbox to \boxaffillen{\usebox{\affilsbox}}%
				\hbox to \boxaffillen{\textsuperscript{\scriptsize #1}{\footnotesize #2} \hfil}
					\vskip -1.5mm
				\ifx#3\empty
				\else
					\vskip .5mm
					\hbox to \boxaffillen{\phantom{\textsuperscript{\scriptsize #1}}\footnotesize{%
							\ifxetex
								\addfontfeatures{Color=tum_mgray}%
							\else
								\color{tum_mgray}%
							\fi
							#3} \hfil}\vskip 1mm
				\fi
				}
	\fi
	}

\def\@varoccasion{}
\def\@vardate{}
%% \date{month}{day}{year}
\renewcommand{\date}[3]{
	\ifx#3\empty
	\else
		\def\@vardate{#1/#2/#3}
	\fi
}
\newcommand{\occasion}[1]{
		\def\@varoccasion{#1}
}
\fi %endif student

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Beamer specific definitions %%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%\useoutertheme{smoothbars}
\usefonttheme[onlymath]{serif}

%%%%%%%%%% sidebar left empty
\setbeamertemplate{sidebar left}{}

%%%%%%%%%% sidebar right empty
\setbeamertemplate{sidebar right}{}

%%%%%%%%%% header
%% \setprojectlogo[opt: website]{filename}{height}
\newcommand{\setprojectlogo}[3][\empty]{
	\newlength{\projectheight}
	\setlength{\projectheight}{#3}
	\def\@projectlogo{#2}
	\setbeamertemplate{headline}{\vspace{2mm}
		\hspace{0mm plus 1fill}
		\ifx#1\empty
			\includegraphics[height=\projectheight]{\@projectlogo}
		\else
			\href{#1}{\includegraphics[height=\projectheight]{\@projectlogo}}
		\fi
		\hspace{2mm}
		\addtolength{\projectheight}{2mm}
		\vspace{-\projectheight}
	%\usebeamertemplate***{navigation symbols}
}}


%%%%%%%%%% footer
\setbeamertemplate{footline}{
\setlength{\bottomlinelen}{\textwidth}
\addtolength{\bottomlinelen}{-6mm}
\if@longpres 
	\ifnum\thepage>1
		\ifxetex
			\includegraphics[width=127.5mm]{itr_logo_foot_full_3}
			\hspace{-108mm} \raisebox{6.5mm}{\insertnavigation{85mm}{}{}}
			\hspace{-0.9mm} \raisebox{4mm}{\scriptsize\insertframenumber}	
		\else
			\ifpdf
				\includegraphics[width=127.5mm]{itr_logo_foot_full_3}
				\hspace{-108mm} \raisebox{6.5mm}{\insertnavigation{85mm}{}{}}
				\hspace{-0.9mm} \raisebox{4mm}{\scriptsize\insertframenumber}
			\else
				\hspace{2.8mm}\raisebox{.7mm}{\includegraphics[width=125.1mm]{itr_logo_foot_full_3}}
				\hspace{-110.8mm} \raisebox{6.5mm}{\insertnavigation{85mm}{}{}}
				\hspace{-0.9mm} \raisebox{4mm}{\scriptsize\insertframenumber}
			\fi%\ifpdf
		\fi%\ifxetex
	\else
			\href{http://www.itr.ei.tum.de}{\includegraphics[width=128mm]{itr_logo_foot_full}}
	\fi%\ifnum\thepage>1
\else
	\ifnum\thepage>1
		\ifxetex
			\includegraphics[width=127.5mm]{itr_logo_foot_full_small_3}
			\hspace{-108mm} \raisebox{3.9mm}{\insertnavigation{85mm}{}{}}
			\hspace{-0.9mm} \raisebox{2.4mm}{\scriptsize\insertframenumber}	
		\else
			\ifpdf
				\includegraphics[width=127.5mm]{itr_logo_foot_full_small_3}
				\hspace{-108mm} \raisebox{3.9mm}{\insertnavigation{85mm}{}{}}
				\hspace{-0.9mm} \raisebox{2.4mm}{\scriptsize\insertframenumber}
			\else
				\hspace{2.8mm}\raisebox{.7mm}{\includegraphics[width=125.1mm]{itr_logo_foot_full_small_3}}
				\hspace{-110.8mm} \raisebox{3.9mm}{\insertnavigation{85mm}{}{}}
				\hspace{-0.9mm} \raisebox{2.4mm}{\scriptsize\insertframenumber}
			\fi%\ifpdf
		\fi%\ifxetex
	\else
			\href{http://www.itr.ei.tum.de}{\includegraphics[width=128mm]{itr_logo_foot_full_small}}
	\fi%\ifnum\thepage>1
\fi%longpres
}

%%%%%%%%%% standard navigation bar for long presentations
\if@longpres   
\else
%%%%%%%%%% default for short presentations
%%%%%%%%%% only sections and one dot per frame in the navigation bar
	\let\ORIGsection=\section
	\renewcommand{\section}[2][\empty]{
			\ifx#1\empty 
				\ORIGsection[#2]{#2}
				\subsection*{dummy}
			\else
				\ORIGsection[#1]{#2}
				\subsection*{dummy}
			\fi
	}
\fi

%%%%%%%%%% title page
%%%%% for student presentations
\if@student
\setbeamertemplate{title page}{
	\if@center
		\centering
		\usebeamerfont{title}\usebeamercolor[fg]{title}\textbf{\inserttitle}\par
		\usebeamerfont{author}
		\begin{table}
			\begin{tabular}{c}
				\hspace{33mm} \\
				\mbox{} \\
				\usebox\authorsboxone\\
				\mbox{} \\
				{\textsl{Lehrstuhl f\"ur Informationstechnische Regelung}} \\
				{\textsl{Technische Universit\"at M\"unchen}} \\
				\mbox {} \\
				{\@vartypeofpres}\\
													\mbox {} \\
													{Betreuer: \@varsupervisor}\\
			\end{tabular}
		\end{table}
	\else		
		\vskip 8mm
		\huge
		\usebeamercolor[fg]{title}
		\textbf{\inserttitle}\\
		\vskip 6mm plus 5filll
		\small
		\usebeamercolor[fg]{author}
		\@varpresenter\\
		\@vartypeofpres\\
		\ifxetex
			{\addfontfeatures{Color=tum_mgray}
				Betreuer: \@varsupervisor}%
		\else
			{\color{tum_mgray}
				Betreuer: \@varsupervisor}%
		\fi
		\vskip 0mm plus 4filll
		{Lehrstuhl f\"ur Informationstechnische Regelung}\\
		\ifxetex
			\addfontfeatures{Color=tum_mgray}
		\else
			\color{tum_mgray}
		\fi
		Technische Universit\"at M\"unchen\\
		\vskip 2mm
	\fi
}
%%%%%%%%%% title page
%%%%% for research presentations
\else
\setbeamertemplate{title page}{
	\if@center
		\begin{center}
			\vskip 2mm plus 4filll
			\usebeamercolor[fg]{title}\huge{\textbf{\inserttitle}}\\
			\vskip 4mm plus 5filll
			\usebeamerfont{author}
			\usebox{\authorsboxone}\\
			\vskip 2mm
			\usebox{\authorsboxtwo}\\
			\vskip 0mm plus 4filll
			\hspace{\stretch{1}}
				\usebox{\affilsbox}
			\hspace{\stretch{1}} %stretch hack!
			\vskip 0mm plus 3filll
		\end{center}
	\else
		\vskip 4mm
		\usebeamercolor[fg]{title}\LARGE{\textbf{\inserttitle}}\\
		\vskip 2mm plus 3filll
		\normalsize	
		\usebeamercolor[fg]{author}
		\usebox{\authorsboxone}\\
		\if@secondline
			%\vskip 0mm minus 4mm
			\usebox{\authorsboxtwo}\\
		\fi
		\vskip 1mm
		\usebox{\affilsbox}
		\vskip 0mm
		\ifx\@vardate\empty
			\textbf{\footnotesize\@varoccasion}
		\else
			\ifx\@varoccasion\empty
				\textbf{\footnotesize\@vardate}
			\else
				\textbf{\footnotesize\@varoccasion, \@vardate}
			\fi
		\fi
	\fi
}

\fi


%%%%%%%%%% frame title bold and centered
\setbeamertemplate{frametitle}
{ 
\if@center
	\begin{centering}
			\vspace{1mm}
			\textbf{\vphantom{Sp}\insertframetitle\vphantom{Sp}}
			\par
	\end{centering}
\else
		\vspace{1mm}
		\textbf{\vphantom{Sp}\insertframetitle\vphantom{Sp}}
		\par
\fi
}


%%%%%%%%% itemize items
%\setbeamertemplate{itemize item}[square]
\setbeamertemplate{itemize item}
{
    %\scriptsize\raise0.25ex\hbox{\donotcoloroutermaths$\blacksquare$}
    \tiny\raise0.4ex\hbox{\donotcoloroutermaths$\blacksquare$}
}
\setbeamertemplate{itemize subitem}
{
    %\scriptsize\raise0.25ex\hbox{\donotcoloroutermaths$\blacksquare$}
    \tiny\raise0.4ex\hbox{\scalebox{0.8}{\donotcoloroutermaths$\blacksquare$}}
}

%%%%%%%%%% FONTS COLORS
\setbeamercolor{title}{fg=tum_blue}
\setbeamercolor{author}{fg=black}
\setbeamercolor{frametitle}{fg=tum_blue}
\setbeamercolor{section in toc}{fg=black}
\setbeamercolor{section in toc shaded}{fg=black}
\setbeamercolor{subsection in toc}{fg=black}
\setbeamercolor{subsection in toc shaded}{fg=black}
\setbeamercolor{itemize item}{fg=black}
\setbeamercolor{itemize subitem}{fg=black}
\setbeamercolor{structure}{fg=black}

%%%%%%%%%%% Navigation Bar
%\setbeamercolor{section in head/foot}{fg=white, bg=tum_blue}
%\setbeamertemplate{section in head/foot shaded}[default][70]

%%%%%%%% Blocks
% Simple block and shadow
\tcbuselibrary{skins}
\usetikzlibrary{shadows}
\if@noshadow
	\tcbset{ 
%		skin=enhanced, %comment Kimmel: enhanced screws up the footline in windows
		boxsep=.5mm, 
		left=0mm,
		top=0.5mm,
		bottom=0.5mm,
		right=0mm,
		coltitle=white,
		colframe=tum_blue,
		colback=white, 
		fonttitle=\bfseries
	}
\else
	\tcbset{ 
%		skin=enhanced,
		frame style={drop shadow},
		boxsep=.5mm, 
		left=0mm,
		top=0.5mm,
		bottom=0.5mm,
		right=0mm,
		coltitle=white,
		colframe=tum_blue,
		colback=white, 
		fonttitle=\bfseries
	}
\fi
\newcommand{\simpleblock}[1]{%
\vskip 2.5mm%
	\begin{tcolorbox}%
	#1%
	\end{tcolorbox}		
	\vskip .5mm%
}
	
\renewenvironment{block}[1]{%
	\vskip 2.5mm%
	\begin{tcolorbox}[title={#1}]
}
{%
	\end{tcolorbox}%
	\vskip .5mm
}%


% Alert environment
\setbeamercolor{alerted text}{fg=tum_orange}


%%%%%%%% Bibliography
\renewcommand{\bibfont}{\normalfont\tiny}
\DeclareFieldFormat*{title}{\textbf{\MakeCapital{#1}}}
%prevent wrong order of names for first author
\DeclareNameAlias{author}{default}
%remove heading
\defbibheading{bibliography}[]{}

\@ifpackagelater{biblatex}{2011/06/01}
{	
	%newer version
	\ExecuteBibliographyOptions{maxbibnames=8, minbibnames=6}
	\setbeamertemplate{bibliography item}{\makebox(7,1)[rt]{\href{\thefield{url}}{\includegraphics[width=4mm]{pdf_logo}}}}
}
{
	%older version
	%does not work
	%\setbeamertemplate{bibliography item}{\makebox(7,1)[rt]{\href{}{\includegraphics[width=4mm]{pdf_logo}}}}
	%to remove numbers [1] and so on
	\defbibenvironment{bibliography}
	{\list{}
		{
		%\settowidth{\labelwidth}{}
		%To align with headline, no logo since old version
		\setlength{\leftmargin}{0cm}%
		%\setlength{\rightmargin}{\labelwidth}%
		%\setlength{\labelsep}{\biblabelsep}%
		%\addtolength{\leftmargin}{\labelsep}%
		%\setlength{\itemsep}{\bibitemsep}%
		%\setlength{\parsep}{\bibparsep}
		}}
		{\endlist}
	{\item}
	\ExecuteBibliographyOptions{maxbibnames=8, minbibnames=6}
	\DeclareFieldFormat*{title}{\newline\textbf{\MakeCapital{#1}.}\newline}
}
\setbeamercolor{bibliography entry location}{fg=gray,bg=white}
\setbeamercolor{bibliography entry note}{fg=gray,bg=white}

%%% different cite commands
\let\ORIGcite=\cite
\newcommand{\bcite}[1]{[\ORIGcite{#1}]}
\renewcommand{\cite}[1]{{\footnotesize[\ORIGcite{#1}]}}
\newcommand{\scite}[1]{{\small[\ORIGcite{#1}]}}
%
%%%% cite command for variable number of names
\newrobustcmd{\varcite}[2]{%
  \AtNextCite{\defcounter{maxnames}{#2}\defcounter{minnames}{#2}}\cite{#1}}


%%%%%%%%%% sync page counter with frame counter
%%%%%%%%%%      only useful in conjunction with:
%%%%%%%%%%      \documentclass[hyperref={pdfpagelabels=true}]{beamer}
\renewcommand{\thepage}{\insertframenumber}

%%%%% math definitions
\newcommand{\argmin}{\operatornamewithlimits{arg\,min}}
\newcommand{\argmax}{\operatornamewithlimits{arg\,max}}
\renewcommand{\d}{\, \mathrm{d}}
