CXXFLAGS="-std=c++11"

lexical_analyzer:
	g++ $(CXXFLAGS) lexical_analyzer.cpp -o lexical_analyzer
	./lexical_analyzer
	rm lexical_analyzer

clean:
	cp *.cpp ../
	cp Makefile ../
	rm *
	cp ../*.cpp ./
	cp ../Makefile ./
