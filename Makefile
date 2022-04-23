build: clean
	@gcc -ggdb main.c -m32 -g -o build/app

run: build
	@./build/app

clean:
	@rm -rf build/
	@mkdir build/