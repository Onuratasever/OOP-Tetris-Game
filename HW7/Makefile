all: clear compile run clean

compile: driver1.java driver2.java
	@javac driver1.java
	@javac driver2.java

run:
	@java driver2
	@java driver1	

clean:
	@rm -rf */*.class
	@rm -rf */*.exe
	@rm -rf */*.html
	@rm -rf */*.css
	@rm -rf */*.js
	@rm -f *.class
	@rm -f *.exe
	@rm -f *.html
	@rm -f *.css
	@rm -f *.js
	@rm -f element-list
	@rm -rf legal
	@rm -rf resources
	@rm -rf script-dir

clear:
	@clear