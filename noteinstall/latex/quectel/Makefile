pdf : clean main.tex
	xelatex main.tex
	xelatex main.tex
clean :
	find ./ -maxdepth 1 -regextype posix-egrep ! -regex ".*\.tex|.*Makefile" -type f -delete 
