build: clean
	@gcc -ggdb main.c -o build/app

run: build
	@./build/app

clean:
	@rm -rf build/
	@mkdir build/