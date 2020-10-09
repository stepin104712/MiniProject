SRC = unity/unity.c\
src/super_markett.c\
test/test_super_markett.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = SUPER_MARKETT.exe

$(PROJECT_NAME):$(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)
run : $(PROJECT_NAME)
	./${PROJECT_NAME}
doc:
	make -C documentation
clean:
	rm -rf $(PROJECT_NAME) documentation/html