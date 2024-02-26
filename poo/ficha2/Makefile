.PHONY: compile update exe clean cleanAll

compile: Main.java
	javac Main.java

update: Implementacao.java
	javac -d . Implementacao.java

exe: $(compile)
	java Main

clean: 
	rm *.class

cleanAll: 
	rm ./*.class pacote/*.class
