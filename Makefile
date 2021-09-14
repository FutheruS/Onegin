SOURCE = source/*.cpp

build:
	g++ $(SOURCE) -o Onegin.exe
clean:
	rm -f Onegin.exe
