.PHONY: compile update exe clean cleanAll

compile: Main.java
	javac Main.java

update: pacote/Implementacao.java
	javac -d . pacote/Implementacao.java

exe: $(compile)
	java Main

clean: 
	rm *.class

cleanAll: 
	rm ./*.class pacote/*.class
